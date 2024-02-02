/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:31:13 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/02 11:34:58 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap constructed" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructed" << std::endl;
}

FragTrap::FragTrap(FragTrap &ob) : ClapTrap(ob)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = ob;
}

FragTrap& FragTrap::operator=(FragTrap &ob)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	this->name = ob.name;
	this->hitPoints = ob.hitPoints;
	this->energyPoints = ob.energyPoints;
	this->attackDamage = ob.attackDamage;

	return *this;	
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap "<< this->name << " requested a high five!" << std::endl;
}
