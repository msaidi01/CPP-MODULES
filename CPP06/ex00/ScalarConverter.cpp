/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:12:26 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/03 20:26:30 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>

bool isChar(std::string toConvert)
{
    if (toConvert.length() != 3 || *toConvert.begin() != '\'' || *toConvert.rbegin() != '\'')
        return false;
    return true;
}

bool ft_isdigit(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
			return false;
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f' && str[i] != '+' && str[i] != '-')
			return false;
	}
	return true;
}

bool checkInput(std::string toConvert)
{
    if (!toConvert.empty() && ft_isdigit(toConvert))
        return true;
    return false;
}

void ScalarConverter::Convert(std::string toConvert)
{
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
    if (toConvert == "nan" || toConvert == "nanf")
    {
        std::cout << "Char : " << "impossible" << std::endl;
        std::cout << "int : " << "impossible" << std::endl;
        std::cout << "float : " << "nanf" << std::endl;
        std::cout << "double : " << "nan" << std::endl;
    }
    if (toConvert == "+inf" || toConvert == "+inff" || toConvert == "inf" || toConvert == "inff"
        || toConvert == "-inf" || toConvert == "-inff")
    {
        std::cout << "Char : " << "impossible" << std::endl;
        std::cout << "int : " << "impossible" << std::endl;
        std::cout << "float : " << toConvert << std::endl;
        std::cout << "double : " << toConvert << std::endl;
    }
    if (checkInput(toConvert))
    {
        double d = atof(toConvert.c_str());
        if (d > 127 || d < 32)
            std::cout << "Char : " << "Non displayable" << std::endl;
        else
            std::cout << "Char : " << static_cast<char>(d) << std::endl;
        std::cout << "int : " << static_cast<int>(d) << std::endl;
        std::cout << "float : " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double : " << d << std::endl;
    }
    else
        std::cout << "Error : Invalid input" << std::endl;
}
