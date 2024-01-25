/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:47:25 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/25 04:07:35 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
#include <stdlib.h>

bool CheckSpc(std::string str)
{	
	for(int i=0; i < (int)str.length() ; i++)
		if (str[i] != ' ' || str[i] != '\t')
			return false;
	return true;
}

void	ShowTab()
{
	std::cout << "+-------------------------------------------+"<< std::endl;
    std::cout <<"|" << std::setw(10) << "index" <<"|" << std::setw(10) << "first name" << "|" << std::setw(10)
    << "last name" <<"|" << std::setw(10) << "nickname" << "|" <<std::endl;
    std::cout << "+-------------------------------------------+"<< std::endl;
       
}


void ListContacts(Contact *BookContact, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "|" << std::setw(10)<< i;
        if (BookContact[i].GetFirstName().size() > 9)
            std::cout << "|" << std::setw(9) << BookContact[i].GetFirstName().substr(0, 9) << ".";
        else
            std::cout << "|" << std::setw(10) << BookContact[i].GetFirstName();
        if (BookContact[i].GetLastName().size() > 9)
            std::cout << "|" << std::setw(9) << BookContact[i].GetLastName().substr(0, 9) << ".";
        else
            std::cout << "|" << std::setw(10) << BookContact[i].GetLastName();
        if (BookContact[i].GetNickName().size() > 9)
            std::cout << "|" << std::setw(9) << BookContact[i].GetNickName().substr(0, 9) << ".";
        else
            std::cout << "|" << std::setw(10) << BookContact[i].GetNickName();
        std::cout << "|" << std::endl;
    }
    std::cout << "+-------------------------------------------+"<< std::endl;
}

bool ShowMore(Contact *BookContact, int size)
{
    std::string str;
    int in;
    std::cin.ignore();
    while (std::cin.good() && CheckSpc(str))
    {
        std::cout << "Enter Index or (.) to go back: ";
        std::getline(std::cin, str);
    }
    if (!str.compare("."))
        return 0;
    if(!str.compare("0")||!str.compare("1")||!str.compare("2")||!str.compare("3")||!str.compare("4")
        ||!str.compare("5")||!str.compare("6")||!str.compare("7"))
    {
        in = atoi(str.c_str());
        if (in < size)
        {
            std::cout << "first name: " << BookContact[in].GetFirstName()<< std::endl;
            std::cout << "last name: " << BookContact[in].GetLastName()<< std::endl;
            std::cout << "nickname: " << BookContact[in].GetNickName()<< std::endl;
            std::cout << "Number: " << BookContact[in].GetNum()<< std::endl;
            std::cout << "Darkest secret: " << BookContact[in].GetDarkestSecret()<< std::endl;
        }
        else {
            std::cout << "Index not found"<<std::endl;
        }
    }
    else {
        std::cout << "Index not found"<<std::endl;
    }
    return (1);
}

void Phonebook::SEARCH()
{
    if (Size == 0)
    {
        std::cout << "Save at least 1 contact" << std::endl;
        return ;
    }
	ShowTab();
	ListContacts(BookContact, Size);
    if (!ShowMore(BookContact, Size))
        return;
}