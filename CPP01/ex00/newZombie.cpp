/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:40:42 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/28 17:58:56 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie* newZombie(std::string name)
{
    Zombie *bo3o = new Zombie(name);
    return bo3o;
}