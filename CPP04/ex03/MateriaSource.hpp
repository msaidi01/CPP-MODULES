/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:46:52 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/04 18:16:42 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
    AMateria* inventory[4];
    public:
    MateriaSource();
    MateriaSource(MateriaSource& ob);
    MateriaSource& operator=(MateriaSource& ob);
    ~MateriaSource();


    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);
};

#endif