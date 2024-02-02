/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:01:12 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/02 18:25:46 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
    protected:
    std::string type;
    public:
    Dog();
    Dog(Dog &ob);
    Dog& operator=(Dog &ob);
    ~Dog();

    std::string getType();
    
    void makeSound();
    
    
};


#endif