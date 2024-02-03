/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:34:39 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/03 20:11:04 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
    protected:
    std::string type;
    public:
    Animal();
    Animal(Animal &ob);
    Animal& operator=(Animal &ob);
    virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const = 0;
};


#endif