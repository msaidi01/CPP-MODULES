/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:52:59 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/31 06:43:11 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <string>

RPN::RPN() : str(""), nums() {}

RPN::RPN(std::string input) : str(input), nums() {}

RPN::RPN(const RPN &rpn) : str(rpn.str), nums(rpn.nums) {}

RPN &RPN::operator=(const RPN &rpn)
{
	if (this != &rpn)
	{
		str = rpn.str;
		nums = rpn.nums;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::setStr(std::string input)
{
	str = input;
}

std::string RPN::getStr()
{
	return str;
}

bool isNumber(char str)
{
	if ((str > '0' && str < '9' )|| str == '-' || str == '+' || str == '*' || str == '/')
		return true;
	return false;
}

void RPN::parseCalculate()
{
	if (str.empty())
	{
		std::cout << "Error: empty string" << std::endl;
		return;
	}
	std::istringstream iss(str);
	
	while (std::getline(iss, str, ' '))
	{
		if (str.size() != 1 || !isNumber(str[0]))
		{
			std::cout << "Error: invalid character" << std::endl;
			return;
		}
		if (str == "+" || str == "-" || str == "*" || str == "/")
		{
			if (nums.size() < 2)
			{
				std::cout << "Error: invalid operation" << std::endl;
				return;
			}
			int a = nums.top();
			nums.pop();
			int b = nums.top();
			nums.pop();
			if (str == "+")
				nums.push(b + a);
			else if (str == "-")
				nums.push(b - a);
			else if (str == "*")
				nums.push(b * a);
			else if (str == "/")
			{
				if (a == 0){
					std::cout << "Error: division by zero" << std::endl;
					return;
				}
				nums.push(b / a);	
			}
		}
		else{
			nums.push(atoi(str.c_str()));
		}
	}
	if (nums.size() != 1)
		std::cout << "Error: invalid operation" << std::endl;
	else
		std::cout << nums.top() << std::endl;
}
