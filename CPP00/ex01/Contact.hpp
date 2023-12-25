/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:42:46 by msaidi            #+#    #+#             */
/*   Updated: 2023/12/23 23:20:26 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
	std::string  FirstName;
	std::string  LastName;
	std::string  NickName;
	std::string  DarkestSecret;
	std::string  Number;
	public:
	void SetFirstName(std::string firstname);
	void SetLastName(std::string lastname);
	void SetNickName(std::string nickname);
	void SetDarkestSecret(std::string darkestsecret);
	void SetNum(std::string num);

	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickName();
	std::string GetDarkestSecret();
	std::string GetNum();
};

#endif