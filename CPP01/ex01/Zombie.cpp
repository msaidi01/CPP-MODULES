/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:40:47 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/26 02:09:50 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
}

Zombie::Zombie()
{}

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << this->name << ": tehla f rassek al batal" << std::endl;
}
