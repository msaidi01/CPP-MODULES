/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:09:42 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/29 08:03:15 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <string>
#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon(NULL)
{}
void HumanB::setWeapon(Weapon &arm)
{
    this->weapon = &arm;
}

void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
     std::cout << name << " has no weapon" << std::endl;
}
std::string HumanB::getWeapon()
{
    return weapon->getType();
}
