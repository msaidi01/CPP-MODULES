/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:40:38 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/26 00:17:00 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "address of str       ::> "<< str<<std::endl;
    std::cout << "address of stringPTR ::> "<< stringPTR << std::endl;
    std::cout << "address of stringREF ::> "<< &stringREF << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "value of str       ::> "<< str<<std::endl;
    std::cout << "value of stringPTR ::> "<< *stringPTR << std::endl;
    std::cout << "value of stringREF ::> "<< stringREF << std::endl;
    
}
