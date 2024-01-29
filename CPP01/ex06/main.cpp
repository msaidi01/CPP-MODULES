/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:51:37 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/28 17:49:34 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    if (ac == 2)
    {
        std::string level = av[1];
        harl.complain(level);
        return 0;
    }
    std::cout << "Invalid argument" << std::endl;
    
}