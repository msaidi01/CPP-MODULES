/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:17:57 by msaidi            #+#    #+#             */
/*   Updated: 2024/04/01 09:38:12 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp" 
#include <algorithm>
#include <cstddef>
#include <utility>
#include <iostream>
#include <vector>

PmergeMe::PmergeMe()
{
    strug = 0;
}

PmergeMe::PmergeMe(const PmergeMe &ob)
{
    *this = ob;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &ob)
{
    strug = ob.strug;
    return *this;
}

void PmergeMe::setStrug(int s)
{
    strug = s;
}

int PmergeMe::getStrug() const
{
    return strug;
}

void PmergeMe::merge(std::vector<std::pair<int, int> > &pairs)
{
     if (pairs.size() == 1)
        return;

    std::vector<std::pair<int, int> > left(pairs.begin(), pairs.begin() + pairs.size() / 2);
    std::vector<std::pair<int, int> > right(pairs.begin() + pairs.size() / 2, pairs.end());


    merge(left);
    merge(right);
    
    size_t i = 0 , l = 0, r = 0;
    while (l < left.size() && r < right.size())
    {
        if (left[l].first < right[r].first)
        {
            pairs[i] = left[l];
            l++; 
        }
        else
        {
            pairs[i] = right[r];
            r++;
        }
        i++;
    }
    while (l < left.size())
    {
        pairs[i] = left[l];
        l++;
        i++;
    }
    while (r < right.size())
    {
        pairs[i] = right[r];
        r++;
        i++;
    }
}

std::vector<int> generateJacobSeq(size_t size)
{
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    std::cout << size << std::endl;
    for (size_t i = 2; i < size; i++)
    {
        if (jacob[i - 1] + 2 * jacob[i - 2] <= (int)size - 1)
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
    
    for (int i = 0; i < (int)jacob.size(); i++)
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

void PmergeMe::createPairs(std::vector<int> &args)
{
    if (args.size() == 1)
    {
        std::cout << args[0] << std::endl;
        return;
    }
    if (args.size() % 2 != 0)
	{
		setStrug(args.back());
		args.pop_back();
	}
    
    std::vector<std::pair<int, int> > pairs;
    
    for (size_t i = 0; i < args.size(); i += 2)
    {
        pairs.push_back(std::make_pair(args[i], args[i + 1]));
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
    merge(pairs);

    std::vector<int> main;
    std::vector<int> pend;

    for (size_t i = 0; i < pairs.size(); i++)
    {
        main.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }
    main.insert(main.begin(), *pend.begin());
    
    std::vector<int> jacob = generateJacobSeq(pend.size());
    std::vector<int> Index = generateIndexSeq(jacob, pend.size());
    
    std::vector<int> new_pend;
    for (int i = 0; i < (int)Index.size(); i++){
        new_pend.push_back(pend[Index[i]]);   
    }
    std::vector<int>::iterator it;
    for (int i = 0; i < (int)new_pend.size(); i++){
        it = (std::lower_bound(main.begin(), main.end(), new_pend[i]));
        main.insert(it, new_pend[i]);
    }
    if (strug != 0){
        it = (std::lower_bound(main.begin(), main.end(), strug));
        main.insert(it, strug);
    }
    for (size_t i = 0; i < main.size(); i++)
    {
        std::cout << main[i] << " ";
    }
}
