/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:12:33 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/03 19:36:33 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    private:
    ScalarConverter();
    ScalarConverter(ScalarConverter &ob);
    ScalarConverter& operator=(ScalarConverter &ob);
    ~ScalarConverter();
    public: 
    static void Convert(std::string);
    
};

#endif