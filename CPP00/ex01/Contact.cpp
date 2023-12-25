/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:17:26 by msaidi            #+#    #+#             */
/*   Updated: 2023/12/23 23:20:06 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>

void    Contact::SetFirstName(std::string firstname)
{
	FirstName = firstname;
}
void    Contact::SetLastName(std::string lastname)
{
	LastName = lastname;
}
void    Contact::SetNickName(std::string nickname)
{
	NickName = nickname;
}
void    Contact::SetDarkestSecret(std::string darkestsecret)
{
	DarkestSecret = darkestsecret;
}
void    Contact::SetNum(std::string num)
{
	Number = num;
}
//getters
std::string Contact::GetFirstName()
{
	return FirstName;
}
std::string Contact::GetLastName()
{
	return LastName;
}
std::string Contact::GetNickName()
{
	return NickName;
}
std::string Contact::GetDarkestSecret()
{
	return DarkestSecret;
}
std::string Contact::GetNum()
{
	return Number;
}
