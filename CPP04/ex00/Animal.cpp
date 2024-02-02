/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:45:58 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/02 17:59:22 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal &ob)
{
	std::cout << "Animal copy constructor called" << std::endl;
	if (this != &ob) {
		*this = ob;
	}
}

Animal& Animal::operator=(Animal &ob)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &ob) {
		this->type = ob.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
