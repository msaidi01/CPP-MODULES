/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:17:29 by msaidi            #+#    #+#             */
/*   Updated: 2023/12/25 05:52:59 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <cctype>
#include <iostream>
#include <ostream>
#include <string>

void	Phonebook::SetSize()
{
	Size++;
}
int	Phonebook::GetSize()
{
	return Size;
}

bool CheckStr(std::string str)
{
	if (str.empty())
		return false;
	return true;
}
bool ft_isdigit(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool CheckSpc(std::string str)
{	
	for(int i=0; i < (int)str.length() ; i++)
		if (str[i] != ' ' || str[i] != '\t')
			return false;
	return true;
}
void FillContact(Contact BookContact)
{
	std::string str;

	std::cin.ignore();
	while (std::cin.good() && CheckSpc(str))
	{
		std::cout << "First name : ";
		std::getline(std::cin, str);
	}
	BookContact.SetFirstName(str);
	str.clear();
	while (std::cin.good() && CheckSpc(str))
	{
		std::cout << "Last name : ";
		std::getline(std::cin, str);
	}
	BookContact.SetLastName(str);
	str.clear();
	while (std::cin.good() && CheckSpc(str))
	{
		std::cout << "Nickname : ";
		std::getline(std::cin, str);
	}
	BookContact.SetNickName(str);
	str.clear();
	while (std::cin.good() && CheckSpc(str))
	{
		std::cout << "Darkest secret : ";
		std::getline(std::cin, str);
	}
	BookContact.SetDarkestSecret(str);
	str.clear();
	while (std::cin.good() && CheckSpc(str))
	{
		std::cout << "Number : ";
		std::getline(std::cin, str);
		if (!ft_isdigit(str))
		{
			str.clear();
			continue;
		}
	}
	BookContact.SetNum(str);
	str.clear();
	
}

void Phonebook::PbInit()
{
	std::cout << "         >>PhoneBook<<" << std::endl;
	std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
}

void Phonebook::ADD()
{
	Index = 0;
	FillContact(BookContact[Index]);
}