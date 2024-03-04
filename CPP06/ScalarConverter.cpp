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
#include <iostream>

bool isChar(std::string toConvert)
{
    if (toConvert.length() != 3 || *toConvert.begin() != '\'' || *toConvert.rbegin() != '\'')
        return false;
    return true;
}


void ScalarConverter::Convert(std::string toConvert)
{
    if (isChar(toConvert))
    {
        if (toConvert[1] > 31 && toConvert[1] < 127)
            std::cout << "Char : " << toConvert[1] << std::endl;
        else
            std::cout << "Char : " <<  "Non displayable" << std::endl;
        std::cout << "Char : " << toConvert[1] << std::endl;
        std::cout << "Char : " << toConvert[1] << std::endl;
        std::cout << "Char : " << toConvert[1] << std::endl;
        
    }
}