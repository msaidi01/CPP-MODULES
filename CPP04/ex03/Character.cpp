/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:57:35 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/05 13:52:23 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include <iostream>

Character::Character()
{
    std::cout << "Character default constructor" << std::endl;
    for (int i = 0; i < 4; i++){
        this->inventory[i] = 0;
    }
}
Character::Character(std::string name)
{
    std::cout << "Character constructor" << std::endl;
    this->name = name;
    for (int i = 0; i < 4; i++)
        this->inventory[i] = 0;
}

std::string const & Character::getName() const 
{
    return this->name;
}

Character::Character(Character &ob)
{
    std::cout << "Character copy constructor" << std::endl;
    if (this != &ob)
    {
        *this = ob;
    }
}

Character& Character::operator=(Character &ob)
{
    std::cout << "Character copy assingment operator" << std::endl;
    if (this != &ob)
    {
        this->name = ob.getName();
        for (int i = 0; i < 4; i++){
            if (this->inventory[i])
                delete this->inventory[i];
            this->inventory[i] = 0;
            if (ob.inventory[i])
                this->inventory[i] = ob.inventory[i]->clone();
        }
    }
    return *this;
}
	
Character::~Character()
{
    std::cout << "Character destructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
    }
}


void Character::equip(AMateria* m)
{
    int i = 0;
    
    while (i < 4 && this->inventory[i])
        i++;
    if (i < 4)
    {
        this->inventory[i] = m;
        return ;
    }
}

void Character::unequip(int idx)
{
    if (idx >= 4 || idx < 0){
        std::cout << "the slot reached not valid!" << std::endl;
        return ;
    }
    else if (!this->inventory[idx]){
        std::cout << "cannot unequip empty slot" << std::endl;
        return ;
    }
    MateriaSource save;
    save.learnMateria(this->inventory[idx]);
    std::cout << this->name << " unequipped " << this->inventory[idx]->getType() << std::endl;
    this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx > 3 || idx < 0)
    {
        std::cout << "Invalid Index" << std::endl;
        return ;
    }
    if (this->inventory[idx]){
        this->inventory[idx]->use(target);
    }
    else {
    std::cout << "no materia found with that index"<< std::endl;
    } 
}
