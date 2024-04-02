/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:17:57 by msaidi            #+#    #+#             */
/*   Updated: 2024/04/02 06:57:45 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp" 
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <utility>
#include <iostream>

PmergeMedeq::PmergeMedeq(): strug(0)
{}

PmergeMedeq::PmergeMedeq(const PmergeMedeq &ob)
{
    if (this != &ob)
    {
        *this = ob;
    }
}

PmergeMedeq::~PmergeMedeq()
{}

PmergeMedeq &PmergeMedeq::operator=(const PmergeMedeq &ob)
{
    if (this != &ob)
    {
        this->strug = ob.strug;
        this->deqSorted = ob.deqSorted;
    }
    return *this;
}


void PmergeMedeq::setStrug(int s)
{
    strug = s;
}

int PmergeMedeq::getStrug() const
{
    return strug;
}

std::deque<int> &PmergeMedeq::getDeqSorted()
{
    return deqSorted;
}

void PmergeMedeq::setTime(double t)
{
    time = t;
}

double PmergeMedeq::getTime()
{
    return time;
}

// deque

std::deque<int> generateJacob(size_t size)
{
    std::deque<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    for (size_t i = 2; i < size; i++)
    {
        if (jacob[i - 1] + 2 * jacob[i - 2] <= (int)size - 1)
            jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
        else
            break;
    }
    return jacob;
}

bool findDeq(std::deque<int> &vec, int val)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (vec[i] == val)
            return true;
    }
    return false;
}

std::deque<int> generateIndex(std::deque<int> &jacob, size_t size)
{
    std::deque<int> index;
    std::deque<int> res;
    
    for (size_t i = 0; i < size; i++){
        index.push_back(i);
    }
    
    for (int i = 0; i < (int)jacob.size(); i++)
    {
        for (int j = 0; j < (int)index.size(); j++)
        {
            if(index[j] == jacob[i] && findDeq(res, index[j]) == false)
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

static void merge(std::deque<std::pair<int, int> > &left, std::deque<std::pair<int, int> > &right,std::deque<std::pair<int, int> > &pairs)
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

void PmergeMedeq::mergeSortdeq(std::deque<std::pair<int, int> > &pairs)
{
    size_t len = pairs.size();
     if (len <= 1)
        return;

    size_t mid = len / 2;
    std::deque<std::pair<int, int> > left;
    std::deque<std::pair<int, int> > right;
    for (size_t i = 0; i < mid; i++){
        left.push_back(pairs[i]);
        std::cout << "left: " << pairs[i].first << " " << pairs[i].second << std::endl;
    }
    for (size_t i = mid; i < len; i++){
        right.push_back(pairs[i]);
        std::cout << "right: " << pairs[i].first << " " << pairs[i].second << std::endl;
    }
    mergeSortdeq(left);
    mergeSortdeq(right);
    
    merge(left, right, pairs);

}


int PmergeMedeq::createPairsdeq(char **av)
{
    clock_t start = clock();
    std::deque<int> args;
    for (int i = 1; av[i]; i++){
        args.push_back(std::atoi(av[i]));
    }
    if (args.size() == 1)
    {
        clock_t end = clock();
        setTime((double)(end - start) / CLOCKS_PER_SEC * 1000000);
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
    std::deque<std::pair<int, int> > pairs; 
    for (size_t i = 0; i < args.size(); i += 2)
    {
        pr[i].first = args[i];
        pr[i].second = args[i + 1];
        if (pr[i].first < pr[i].second)
            std::swap(pr[i].first, pr[i].second);
        pairs.push_back(pr[i]);
    
    }
    mergeSortdeq(pairs);
    
    std::deque<int> main;
    std::deque<int> pend;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    
    std::deque<int> jacob = generateJacob(pend.size());
    std::deque<int> Index = generateIndex(jacob, pend.size());
    
    std::deque<int> new_pend;
    for (size_t i = 0; i < Index.size(); i++){
        new_pend.push_back(pend[Index[i]]);   
    }
    std::deque<int>::iterator it;
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
        this->deqSorted.push_back(main[i]);
    }
    clock_t end = clock();
    setTime((double)(end - start) / CLOCKS_PER_SEC * 1000000);
    
    return 0;
}