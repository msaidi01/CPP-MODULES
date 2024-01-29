/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 06:55:27 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/26 02:06:47 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstddef>
#include <iostream>

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cout << "Number not valid" << std::endl;
        return NULL;
    }
    Zombie *halikat = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        halikat[i].setName(name);
    }
    return halikat;
}