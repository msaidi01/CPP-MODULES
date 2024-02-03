/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:34:00 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/03 19:47:45 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
    const Animal* j[8];

    Dog max;
    Cat leo;
    Brain m;
    Brain c;

    m.setIdeas("jump");
    c.setIdeas("sleep");
    
    max.setBrain(m);
    leo.setBrain(c);
    leo.getBrain().printIdeas();
    max.getBrain().printIdeas();
    m.setIdeas("sleep");
    c.setIdeas("eat");
    max.getBrain().printIdeas();
    leo.getBrain().printIdeas();
    
    for (int i = 0; i < 8; i++)
    {
        if (i < 4)
            j[i] = new Cat();
        else
        j[i] = new Dog();
    }

    for (int i = 0; i < 8; i++)
    {
        j[i]->makeSound();
        delete j[i];
    }
    return 0;
}
