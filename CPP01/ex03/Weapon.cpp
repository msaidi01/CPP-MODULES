/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 01:18:43 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/26 04:15:27 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type)
{
    this->type = type;
}

const std::string& Weapon::getType()
{
    return type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}
