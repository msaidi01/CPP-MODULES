/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:09:52 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/26 03:43:50 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
class Span
{
    private:
    unsigned int n;
    std::vector<int> myArray;
    Span();
    public:
    Span(unsigned int n);
    Span(Span const & src);
    Span & operator=(Span const & src);
    ~Span();
    
    void addNumber(int n);
    int shortestSpan();
    int longestSpan();

    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    
};




#endif