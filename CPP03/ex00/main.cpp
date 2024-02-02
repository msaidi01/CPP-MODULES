/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:06:32 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/02 11:47:46 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>


int main()
{
    ClapTrap zeus("zeus");


    zeus.attack("giant");
    zeus.beRepaired(1);
    zeus.takeDamage(5);
    
    std::cout << "----------------------------" << std::endl;
    
    zeus.attack("goblin");
    zeus.beRepaired(2);
    zeus.takeDamage(1);
}
