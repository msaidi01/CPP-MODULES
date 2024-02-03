/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:36:54 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/03 13:37:47 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &ob)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	if (this != &ob) {
		*this = ob;
	}
}

WrongCat& WrongCat::operator=(WrongCat &ob)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &ob) {
		this->type = ob.type;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getType()
{
    return this->type;
}

void WrongCat::makeSound() const
{
    std::cout << "Miaou miaou" << std::endl;
}
