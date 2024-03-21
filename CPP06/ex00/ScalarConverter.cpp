/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:12:26 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/21 01:56:58 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdio>
#include <iostream>
#include <limits>
#include <cmath>

bool isChar(std::string toConvert)
{
	if (toConvert.length() != 3 || *toConvert.begin() != '\'' || *toConvert.rbegin() != '\'')
		return false;
	return true;
}

bool ft_isdigit(std::string str)
{
	int j = 0;
	size_t found = str.find(".");

	if (found == 0)
		return false;
	if (str[j] == '+' || str[j] == '-')
		j++;
	for (int i = 0; i < 2 && found != std::string::npos; i++)
	{
		found = str.find(".", found + 1);
		if (i >= 1)
			return false;
	}
	for (int i = j; i < (int)str.length() - 1 ; i++)
	{
		if (!std::isdigit(str[i]) && str[i] != '.')
			return false;
	}
	if ((isdigit(str[str.length() - 2]) && str[str.length() - 1] == 'f')|| isdigit(str[str.length() - 1]))
		return true;
	return false;
}

bool pseudoLiterals(std::string toConvert)
{
	if (toConvert == "+inf" || toConvert == "+inff" || toConvert == "-inf"
	|| toConvert == "-inff" || toConvert == "nan")
		return true;
	return false;
}

void printPseudo(std::string toConvert)
{
	if (toConvert == "nan" || toConvert == "nanf")
	{
		std::cout << "Char : " << "impossible" << std::endl;
		std::cout << "int : " << "impossible" << std::endl;
		std::cout << "float : " << "nanf" << std::endl;
		std::cout << "double : " << "nan" << std::endl;
	}
	std::string pseudo[] = {"+inf", "-inf", "+inff", "-inff"};
	int i = 0;
	while (i < 4)
	{
		if (toConvert == pseudo[i])
			break;
		i++;
	}
	if (i < 4)
	{
		std::cout << "Char : " << "Impossible" << std::endl;
		std::cout << "int : " << "Impossible" << std::endl;
		if (i < 2)
		{
			std::cout << "float : " << pseudo[i] << "f" << std::endl;
			std::cout << "double : " << pseudo[i] << std::endl;
		}
		else
		{
			std::cout << "float : " << pseudo[i] << std::endl;
			pseudo[i].erase(pseudo[i].end() - 1);
			std::cout << "double : " << pseudo[i] << std::endl;
		}
	}
}

void ScalarConverter::Convert(std::string toConvert)
{
	if (toConvert.empty())
	{
		std::cout << "Invalid argument to convert!" << std::endl;
		return ;
	}
	if (isChar(toConvert))
	{
		if (toConvert[1] > 31 && toConvert[1] < 127)
			std::cout << "Char : " << toConvert[1] << std::endl;
		else
			std::cout << "Char : " <<  "Non displayable" << std::endl;
		std::cout << "int : " <<  static_cast<int>(toConvert[1]) << std::endl;
		std::cout << "float : " <<  static_cast<float>(toConvert[1]) << ".0f" << std::endl;
		std::cout << "double : " <<  static_cast<double>(toConvert[1]) << ".0" << std::endl;
	}
	else if (pseudoLiterals(toConvert)){
		printPseudo(toConvert);
	}
	else if (ft_isdigit(toConvert))
	{
		double converted = atof(toConvert.c_str());
		
		if (converted > 31 && converted < 127)
			std::cout << "Char : " << static_cast<char>(converted) << std::endl;
		else
			std::cout << "Char : " <<  "Non displayable" << std::endl;
		if (converted < std::numeric_limits<int>::min() || converted > std::numeric_limits<int>::max())
			std::cout << "int : " <<  "Impossible" << std::endl;
		else
			std::cout << "int : " <<  static_cast<int>(converted) << std::endl;
		
		double test = floor(converted);
		
		if (converted == test)
		{
			std::cout << "float : " << static_cast<float>(converted) << ".0f" << std::endl;
			std::cout << "double : " << (converted) << ".0" << std::endl;
		}
		else
		{
			std::cout << "float : " << static_cast<float>(converted) << "f" << std::endl;
			std::cout << "double : " << (converted) << std::endl;
		}
	}
	else
		std::cout << "Error : Invalid input" << std::endl;
}
