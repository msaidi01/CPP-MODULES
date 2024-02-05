/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:46:24 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/04 18:16:53 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"


Ice::Ice()
{
    std::cout << "Ice default constructor" << std::endl;
    this->type = "ice";
}
Ice::Ice(Ice &ob)
{
    std::cout << "Ice copy constructor" << std::endl;
    if (this != &ob){
        *this = ob;
    }
}
Ice& Ice::operator=(Ice &ob)
{
    std::cout << "Ice copy assingment operator" << std::endl;
    if (this != &ob){
        this->type = ob.type;
    }
    return *this;
}
Ice::~Ice()
{
    std::cout << "Ice destructor" << std::endl;
}

Ice* Ice::clone() const
{
    return new Ice();
}

void Ice::setType()
{
    this->type = "ice";
}

std::string Ice::getType()
{
    return this->type;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an " << this->getType() << " at " << target.getName() << " *" << std::endl;
}