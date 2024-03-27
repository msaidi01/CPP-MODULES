/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:09:56 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/26 03:47:56 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
	Span sp = Span(10);
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	} catch (std::exception &e) {
		
		std::cout << e.what() << std::endl;
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "---------------------------" << std::endl;

	std::vector<int> vec;
	vec.push_back(66);
	vec.push_back(55);
	vec.push_back(77);
	vec.push_back(44);
	vec.push_back(33);
	try 
	{
		sp.addNumber(vec.begin(), vec.end());
		
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	

}