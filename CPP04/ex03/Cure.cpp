/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:37:12 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/04 18:13:30 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
{
    std::cout << "Cure default constructor" << std::endl;
    this->setType();
}
Cure::Cure(Cure &ob)
{
    std::cout << "Cure copy constructor" << std::endl;
    if (this != &ob){
        *this = ob;
    }
}
Cure& Cure::operator=(Cure &ob)
{
    std::cout << "Cure copy assingment operator" << std::endl;
    if (this != &ob){
        this->type = ob.type;
    }
    return *this;
}
Cure::~Cure()
{
    std::cout << "Cure destructor" << std::endl;
}

Cure* Cure::clone() const
{
    return new Cure();
}

void Cure::setType()
{
    this->type = "cure";
}

std::string Cure::getType()
{
    return this->type;
}
void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
