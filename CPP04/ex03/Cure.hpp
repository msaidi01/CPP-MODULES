/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 10:33:55 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/04 18:12:13 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include <string>

class Cure : public AMateria
{
    public:
    Cure();
    Cure(Cure &ob);
    Cure& operator=(Cure &ob);
    
    void setType();
    std::string getType();
    Cure* clone() const;
    
    void use(ICharacter& target);
    
    ~Cure();

    
      
};


#endif