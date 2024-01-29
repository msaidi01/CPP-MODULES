/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:51:34 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/28 17:57:26 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
    
}
void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level)
{
    std::string tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4)
    {
        if (level == tab[i])
            break ;
        i++;
    }
    switch (i)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
        this->warning();
        case 3:
            this->error();
            break ;
        default:
            std::cout << "complaining about something else"<< std::endl;
    }
}

