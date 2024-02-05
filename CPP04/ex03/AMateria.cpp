/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:28:19 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/05 12:28:16 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria()
{
    std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
    std::cout << "AMateria constructor" << std::endl;
    this->type = type;
}

AMateria::AMateria(AMateria &ob)
{
    std::cout << "AMateria copy constructor" << std::endl;
    if (this != &ob)
        *this = ob;
}

AMateria& AMateria::operator=(AMateria &ob)
{
    std::cout << "AMateria copy assignment operator" << std::endl;
    if (this != &ob)
    {
        this->type = ob.type;
    }
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor" << std::endl;
    
}

std::string const & AMateria::getType() const 
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria used as abstracted on " << target.getName() << std::endl;
}