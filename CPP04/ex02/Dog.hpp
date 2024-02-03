/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:01:12 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/03 19:38:14 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
    private:
    Brain* brainDog;
    public:
    Dog();
    Dog(Dog &ob);
    Dog& operator=(Dog &ob);
    ~Dog();

    std::string getType();
    void setBrain(Brain &ob);
    Brain getBrain();
    void makeSound() const;
    
    
};


#endif