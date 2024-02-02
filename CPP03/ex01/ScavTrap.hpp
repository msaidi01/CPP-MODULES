/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:42:59 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/02 11:12:56 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
    public:
    ScavTrap(std::string name);
    ScavTrap(ScavTrap &ob);
    ScavTrap& operator=(ScavTrap &ob);

    void guardGate();
    void attack(const std::string& target);
    ~ScavTrap();
};


#endif