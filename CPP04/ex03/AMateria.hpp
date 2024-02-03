/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:25:51 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/03 20:34:04 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class AMateria
{
    protected:
    std::string type;
    public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(AMateria &ob);
    AMateria& operator=(AMateria &ob);
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    // virtual void use(ICharacter& target);
    virtual ~AMateria();
};

#endif
