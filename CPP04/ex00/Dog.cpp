/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:01:34 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/02 18:25:53 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(Dog &ob)
{
	std::cout << "Dog copy constructor called" << std::endl;
	if (this != &ob) {
		*this = ob;
	}
}

Dog& Dog::operator=(Dog &ob)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &ob) {
		this->type = ob.type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType()
{
    return this->type;
}

void Dog::makeSound()
{
    std::cout << "Wouf wouf" << std::endl;
}