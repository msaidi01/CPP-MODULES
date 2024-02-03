/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:59:48 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/03 19:21:47 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
	this->brainCat = new Brain();

}

Cat::Cat(Cat &ob) : brainCat(NULL)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = ob;
}

Cat& Cat::operator=(Cat &ob)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &ob) {
		if (this->brainCat)
		{
			delete this->brainCat;
			this->brainCat = new Brain();
		}
		this->type = ob.getType();
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	if (this->brainCat)
		delete this->brainCat;
}

std::string Cat::getType()
{
    return this->type;
}

void Cat::makeSound() const
{
    std::cout << "Miaou miaou" << std::endl;
}

void Cat::setBrain(Brain &ob)
{
	*this->brainCat = ob;
}
Brain Cat::getBrain()
{
	return *this->brainCat;
}