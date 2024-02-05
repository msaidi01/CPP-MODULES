/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:30:10 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/05 11:19:39 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal &ob)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	if (this != &ob) {
		*this = ob;
	}
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal &ob)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &ob) {
		this->type = ob.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
