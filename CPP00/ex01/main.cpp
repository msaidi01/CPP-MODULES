/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:31:53 by msaidi            #+#    #+#             */
/*   Updated: 2023/12/25 05:53:22 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <ostream>
#include <string>



int main()
{
    Phonebook MyBook;
    std::string input;
    while (1)
    {
        
        MyBook.PbInit();
        std::cin >> input;
        if (!input.compare("ADD"))
        {
            MyBook.ADD();
            MyBook.SetSize();
        }
        else if (!input.compare("SEARCH"))
            std::cout << input<< std::endl;
        else if (!input.compare("EXIT"))
            exit(0);
        else
           std::cout << "ADD, SEARCH, EXIT are the only commands" << std::endl;
    }
}
