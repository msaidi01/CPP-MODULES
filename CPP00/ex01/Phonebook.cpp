/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:17:29 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/19 06:56:29 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

void	Phonebook::SetSize()
{
	Size = 0;
}
void	Phonebook::IndexInc()
{
	if (Index == 8)
		Index = 0;
	else
		Index++;
}
void	Phonebook::SizeInc()
{
	if (Size == 8)
		Size = 8;
	else
		Size++;
}
int	Phonebook::GetSize()
{
	return Size;
}
void	Phonebook::SetIndex()
{
	Index = 0;
}
int	Phonebook::GetIndex()
{
	return Index;
}

bool CheckStr(std::string str)
{
	if (str.empty())
		return true;
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (str[i] != ' ' || str[i] != '\t')
			return false;
	}
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

void Phonebook::PbInit()
{
	std::cout << std::setw(20)<< ">>PhoneBook<<" << std::endl;
	std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
}

void Phonebook::ADD()
{
	std::string str;

	SizeInc();
	std::cin.ignore();
	while (std::cin.good() && CheckStr(str))
	{
		std::cout << "First name : ";
		std::getline(std::cin, str);
	}
	BookContact[Index].SetFirstName(str);
	str.clear();
	while (std::cin.good() && CheckStr(str))
	{
		std::cout << "Last name : ";
		std::getline(std::cin, str);
	}
	BookContact[Index].SetLastName(str);
	str.clear();
	while (std::cin.good() && CheckStr(str))
	{
		std::cout << "Nickname : ";
		std::getline(std::cin, str);
	}
	BookContact[Index].SetNickName(str);
	str.clear();
	while (std::cin.good() && CheckStr(str))
	{
		std::cout << "Darkest secret : ";
		std::getline(std::cin, str);
	}
	BookContact[Index].SetDarkestSecret(str);
	str.clear();
	while (std::cin.good() && CheckStr(str))
	{
		std::cout << "Number : ";
		std::getline(std::cin, str);
		if (!ft_isdigit(str))
		{
			str.clear();
			continue;
		}
	}
	BookContact[Index].SetNum(str);
	str.clear();
	IndexInc();
}