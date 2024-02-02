/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:25:41 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/02 11:30:38 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
    FragTrap(std::string name);
    FragTrap(FragTrap &ob);
    FragTrap& operator=(FragTrap &ob);

	void highFivesGuys( void );
    ~FragTrap();
};



#endif