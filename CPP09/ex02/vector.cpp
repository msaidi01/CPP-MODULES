/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 04:34:53 by msaidi            #+#    #+#             */
/*   Updated: 2024/04/02 06:56:20 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <vector>

PmergeMevec::PmergeMevec(): time(0)
{}

PmergeMevec::PmergeMevec(const PmergeMevec &ob)
{
    if (this != &ob){
        *this = ob;
    }
}

PmergeMevec::~PmergeMevec()
{
}

PmergeMevec &PmergeMevec::operator=(const PmergeMevec &ob)
{
    if ( this != &ob)
    {
        this->strug = ob.strug;
        this->vecSorted = ob.vecSorted;
        this->time = ob.time;
    }
    return *this;
}

void PmergeMevec::setStrug(int s)
{
    strug = s;
}

int PmergeMevec::getStrug() const
{
    return strug;
}

std::vector<int> &PmergeMevec::getVecSorted()
{
    return vecSorted;
}

void PmergeMevec::setTime(double t)
{
    time = t;
}

double PmergeMevec::getTime()
{
    return time;
}

void PmergeMevec::printVec()
{
    std::cout << "After  : ";
    for (size_t i = 0; i < vecSorted.size(); i++){
        std::cout << vecSorted[i] << " ";
    }
    std::cout << std::endl;
}

std::vector<int> generateJacobSeq(size_t size)
{
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    for (size_t i = 2; i < size; i++)
    {
        if (jacob[i - 1] + 2 * jacob[i - 2] < (int)size - 1)
            jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
        else
            break   ;
    }
    return jacob;
}

bool findVec(std::vector<int> &vec, int val)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec[i] == val)
            return true;
    }
    return false;
}

std::vector<int> generateIndexSeq(std::vector<int> &jacob, size_t size)
{
    std::vector<int> index;
    std::vector<int> res;
    
    for (size_t i = 0; i < size; i++){
        index.push_back(i);
    }
    
    for (size_t i = 0; i < jacob.size(); i++)
    {
        for (int j = 0; j < (int)index.size(); j++)
        {
            if(index[j] == jacob[i] && findVec(res, index[j]) == false)
            {
                res.push_back(index[j]);
                index[j] = -1;
                j--;
                while (j >= 0 && index[j] != -1)
                {
                    res.push_back(index[j]);
                    index[j] = -1;
                    j--;
                }
            }
        }
    }
    
    for (size_t j = 0; j < index.size(); j++)
    {
        if (index[j] != -1)
            res.push_back(index[j]);
    }

    return res;
}

static void merge(std::vector<std::pair<int, int> > &left, std::vector<std::pair<int, int> > &right,std::vector<std::pair<int, int> > &pairs)
{
    size_t l = 0;
    size_t r = 0;
    size_t i = 0;
    while (l < left.size() && r < right.size())
    {
        if (left[l].first < right[r].first)
        {
            pairs[i] = left[l];
            i++;
            l++;
        }
        else {
        
            pairs[i] = right[r];
            i++;
            r++;
        }
    }
    while (l < left.size())
    {
        pairs[i] = left[l];
        i++;
        l++;
    }
    while (r < right.size())
    {
        pairs[i] = right[r];
        i++;
        r++;
    }
    
}

void PmergeMevec::mergeSort(std::vector<std::pair<int, int> > &pairs)
{
    size_t len = pairs.size();
     if (len <= 1)
        return;

    size_t mid = len / 2;
    std::vector<std::pair<int, int> > left;
    std::vector<std::pair<int, int> > right;
    for (size_t i = 0; i < mid; i++){
        left.push_back(pairs[i]);
        std::cout << "left: " << pairs[i].first << " " << pairs[i].second << std::endl;
    }
    for (size_t i = mid; i < len; i++){
        right.push_back(pairs[i]);
        std::cout << "right: " << pairs[i].first << " " << pairs[i].second << std::endl;
    }
    mergeSort(left);
    mergeSort(right);
    
    merge(left, right, pairs);

}


int PmergeMevec::createPairs(char **av)
{
    clock_t start = clock();
    std::vector<int> args;
    for (int i = 1; av[i]; i++){
        args.push_back(std::atoi(av[i]));
    }
    if (args.size() == 1)
    {
        clock_t end = clock();
        setTime((double)(end - start) / CLOCKS_PER_SEC * 1000000);
        std::cout << args[0] << std::endl;
        return 1;
    }
    bool zero = false;
    if (args.size() % 2 != 0)
	{
		setStrug(args.back());
        if (getStrug() == 0)
            zero = true;
		args.erase(args.end() - 1);
	}

    std::pair<int, int> pr[args.size()];
    std::vector<std::pair<int, int> > pairs; 
    for (size_t i = 0; i < args.size(); i += 2)
    {
        pr[i].first = args[i];
        pr[i].second = args[i + 1];
        if (pr[i].first < pr[i].second)
            std::swap(pr[i].first, pr[i].second);
        pairs.push_back(pr[i]);
    
    }
    mergeSort(pairs);
    
    std::vector<int> main;
    std::vector<int> pend;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    
    std::vector<int> jacob = generateJacobSeq(pend.size());
    std::vector<int> Index = generateIndexSeq(jacob, pend.size());
    
    std::vector<int> new_pend;
    for (size_t i = 0; i < Index.size(); i++){
        new_pend.push_back(pend[Index[i]]);   
    }
    std::vector<int>::iterator it;
    for (size_t i = 0; i < new_pend.size(); i++){
        it = (std::lower_bound(main.begin(), main.end(), new_pend[i]));
        main.insert(it, new_pend[i]);
    }
    if (strug != 0){
        it = (std::lower_bound(main.begin(), main.end(), strug));
        main.insert(it, strug);
    }
    else if (zero == true){
        it = (std::lower_bound(main.begin(), main.end(), strug));
        main.insert(it, 0);
    }
    for (size_t i = 0; i < main.size(); i++){
        this->vecSorted.push_back(main[i]);
    }
    clock_t end = clock();
    setTime((double)(end - start) / CLOCKS_PER_SEC * 1000000);
    
    return 0;
}