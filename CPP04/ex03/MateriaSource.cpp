/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:58:41 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/05 12:48:13 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor" << std::endl;
    for (int i = 0; i < 4; i++){
        this->inventory[i] = 0;
    }
}

MateriaSource::MateriaSource(MateriaSource &ob) 
{
    std::cout << "MateriaSource copy constructor" << std::endl;
    if (this != &ob)
    {
        *this = ob;
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource &ob)
{
    std::cout << "MateriaSource copy assingment operator" << std::endl;
    if (this != &ob)
    {
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
	
MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
            delete this->inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria* mat)
{
    int i = 0;
    while (this->inventory[i] != 0 && i < 4)
        i++;
    if (i > 3)
    {
        std::cout << "can't learn more than 4 Materias"<<std::endl;
        return ;
    }
    for (int j = 0; j < 4; j++){
        if (this->inventory[j] == mat)
            return ;
    }
    this->inventory[i] = mat;
    std::cout << "materia from type " << mat->getType() << " learned!"<< std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;
    
    while ( i < 4 && this->inventory[i] && this->inventory[i]->getType() != type)
        i++;
    if (i >= 4 || !this->inventory[i])
    {
        std::cout << type << ": invalid materia type!" << std::endl;
        return 0;
    }
    return this->inventory[i]->clone();
}
