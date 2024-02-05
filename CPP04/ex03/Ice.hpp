/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:46:18 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/04 18:04:37 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
    Ice();
    Ice(Ice &ob);
    Ice& operator=(Ice &ob);
    
    void setType();
    std::string getType();
    
    Ice* clone() const;
    void use(ICharacter& target);
    
    ~Ice();

    
      
};


#endif