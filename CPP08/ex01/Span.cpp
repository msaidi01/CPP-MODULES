/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:44:06 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/27 02:27:22 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int N) : n(N){}

Span::Span(Span const & ob)
{
    *this = ob;
}

Span & Span::operator=(Span const & ob)
{
    if (this != &ob)
    {
        this->myArray = ob.myArray;
        this->n = ob.n;
    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int toAdd)
{
    if (myArray.size() < this->n)
        myArray.push_back(toAdd);
    else
        throw std::runtime_error("no space left in the array");
}

int Span::longestSpan()
{
    std::sort(myArray.begin(), myArray.end());
    int sp = (*myArray.rbegin()) - (*myArray.begin());
    return sp;
}
int Span::shortestSpan()
{
    std::sort(myArray.begin(), myArray.end());
    int sp = longestSpan();
    std::vector<int>::iterator it;
    for (it = myArray.begin() + 1; it != myArray.end(); it++)
    {
        if (*it - *(it - 1) < sp)
            sp = *it - *(it - 1);
    }
    return sp;
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (myArray.size() + std::distance(begin, end) > this->n)
        throw std::runtime_error("no enough size to store the whole array");
    myArray.insert(myArray.end(), begin, end);
}
