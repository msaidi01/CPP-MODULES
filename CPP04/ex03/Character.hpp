/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:31:50 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/04 17:24:43 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"


class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4];
	public:
	Character();
	Character(std::string name);
	Character(Character &ob);
	Character& operator=(Character &ob);
	
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	
	~Character();
};




#endif