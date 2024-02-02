/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:06:32 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/02 11:40:39 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
    FragTrap mrda("grade1");

    mrda.attack("giant");
    mrda.beRepaired(1);
    mrda.takeDamage(5);
    
    std::cout << "----------------------------" << std::endl;
    
    mrda.attack("goblin");
    mrda.beRepaired(2);
    mrda.takeDamage(1);

    mrda.highFivesGuys();
}