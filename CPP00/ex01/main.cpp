/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:31:53 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/21 19:49:20 by msaidi           ###   ########.fr       */
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
    MyBook.SetSize();
    MyBook.SetIndex();
    while (1)
    {
        MyBook.PbInit();
        std::cin >> input;
        if (std::cin.eof() || input.empty())
            return (0);
        if (!input.compare("ADD"))
            MyBook.ADD();
        else if (!input.compare("SEARCH"))
           MyBook.SEARCH();
        else if (!input.compare("EXIT"))
            exit(0);
        else
           std::cout << "ADD, SEARCH, EXIT are the only commands" << std::endl;
    }
}
