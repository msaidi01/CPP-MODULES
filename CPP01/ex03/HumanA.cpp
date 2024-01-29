/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 02:31:21 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/26 03:32:15 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &arm): name(name), A(arm)
{}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << A.getType() << std::endl;
}