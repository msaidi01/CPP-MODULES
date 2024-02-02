/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:59:48 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/02 18:26:18 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(Cat &ob)
{
	std::cout << "Cat copy constructor called" << std::endl;
	if (this != &ob) {
		*this = ob;
	}
}

Cat& Cat::operator=(Cat &ob)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &ob) {
		this->type = ob.type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getType()
{
    return this->type;
}

void Cat::makeSound()
{
    std::cout << "Miaou miaou" << std::endl;
}
