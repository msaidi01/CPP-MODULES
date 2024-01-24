/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:17:29 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/22 03:59:34 by msaidi           ###   ########.fr       */
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
	this->Index = (this->Index + 1) % 8;
}
void	Phonebook::SizeInc()
{
	if (Size == 8)
		return ;
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


bool is_spc(std::string s)
{
	for(int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] != ' ' && s[i] != '\t')
			return true;
	}
	return false;
}

bool ft_isdigit(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
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
	while (std::cin.good() && str.empty())
	{
		std::cout << "First name : ";
		std::getline(std::cin, str);
		if (!is_spc(str))
		{
			str.clear();
			continue;
		}
	}
	BookContact[Index].SetFirstName(str);
	str.clear();
	while (std::cin.good() && str.empty())
	{
		std::cout << "Last name : ";
		std::getline(std::cin, str);
		if (!is_spc(str))
		{
			str.clear();
			continue;
		}
	}
	BookContact[Index].SetLastName(str);
	str.clear();
	while (std::cin.good() && str.empty())
	{
		std::cout << "Nickname : ";
		std::getline(std::cin, str);
		if (!is_spc(str))
		{
			str.clear();
			continue;
		}
	}
	BookContact[Index].SetNickName(str);
	str.clear();
	while (std::cin.good() && str.empty())
	{
		std::cout << "Darkest secret : ";
		std::getline(std::cin, str);
		if (!is_spc(str))
		{
			str.clear();
			continue;
		}
	}
	BookContact[Index].SetDarkestSecret(str);
	str.clear();
	while (std::cin.good() && str.empty())
	{
		std::cout << "Number : ";
		std::getline(std::cin, str);
		if (!is_spc(str))
		{
			str.clear();
			continue;
		}
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