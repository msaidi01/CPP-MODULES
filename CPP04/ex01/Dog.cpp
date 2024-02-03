/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:01:34 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/03 19:38:00 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
	this->brainDog = new Brain();
}

Dog::Dog(Dog &ob)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = ob;
}

Dog& Dog::operator=(Dog &ob)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &ob) {
		if (this->brainDog)
		{
			delete this->brainDog;
			this->brainDog = new Brain();
		}
		this->type = ob.getType();
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	if (this->brainDog)
		delete this->brainDog;
}

std::string Dog::getType()
{
    return this->type;
}

void Dog::makeSound() const
{
    std::cout << "Wouf wouf" << std::endl;
}

void Dog::setBrain(Brain &ob)
{
	*this->brainDog = ob;
}
Brain Dog::getBrain()
{
	return *this->brainDog;
}