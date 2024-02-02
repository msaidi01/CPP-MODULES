/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:53:57 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/02 15:30:34 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap constructed" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructed" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &ob) : ClapTrap(ob)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = ob;
}

ScavTrap& ScavTrap::operator=(ScavTrap &ob)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	this->name = ob.name;
	this->hitPoints = ob.hitPoints;
	this->energyPoints = ob.energyPoints;
	this->attackDamage = ob.attackDamage;

	return *this;	
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " has activated gate mode!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if ((unsigned int)this->energyPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ScavTrap "<< this->name << " attacks " << target \
        << ", causing "<< this->attackDamage << " points of damage!" << std::endl;
    }
    else{
        std::cout << "cannot attack : no energy!" << std::endl;
    }
}