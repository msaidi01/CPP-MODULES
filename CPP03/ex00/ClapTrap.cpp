/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:13:06 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/02 10:15:38 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap& ob)
{
    std::cout << "copy constructor called" << std::endl;
    
    *this = ob;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ob)
{
    std::cout << "copy assignment operator called" << std::endl;
    this->name = ob.name;
    this->hitPoints = ob.hitPoints;
    this->energyPoints = ob.energyPoints;
    this->attackDamage = ob.attackDamage;

    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called"<<std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if ((unsigned int)this->energyPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ClapTrap "<< this->name << " attacks " << target \
        << ", causing "<< this->attackDamage << " points of damage!" << std::endl;
    }
    else{
        std::cout << "cannot attack : no energy!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints)
    {
        this->hitPoints -= amount;
        if (this->hitPoints > 0)
        {
            std::cout << "ClapTrap "<< this->name << " took " \
            << amount << " points of damage!" << std::endl;
        }
        else {
            this->hitPoints = 0;
            std::cout << "ClapTrap "<<this->name<< " died!"<<std::endl;
        }
    }
    else
    {
        this->hitPoints = 0;
        std::cout << "ClapTrap "<< this->name << " already dead!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints > 0)
    {
        std::cout << "ClapTrap "<< this->name << " repaired itself and gained " \
        << amount << " hit points!" << std::endl;
        this->energyPoints--;
        this->hitPoints += amount;
        if (this->hitPoints > 10)
            this->hitPoints = 10;
    }
    else{
        std::cout << "ClapTrap "<< this->name << " cannot repair : No energy!" << std::endl;
    }
    
}
