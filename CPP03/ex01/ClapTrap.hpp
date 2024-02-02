/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:23:42 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/02 10:44:38 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>


class ClapTrap
{
	protected:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
	public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &ob);
	ClapTrap& operator=(const ClapTrap& ob);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	~ClapTrap();
};


#endif
