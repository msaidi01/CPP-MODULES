/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:34:00 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/05 11:29:30 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
// #include <cstdlib>


// void l()
// {
//     system("leaks Brain");
// }

int main()
{

    // atexit(l);
    const Animal* j[8];

    Dog max;
    Brain m;

    m.setIdeas("jump");

    
    max.setBrain(m);
    max.getBrain().printIdeas();

    m.setIdeas("sleep");
    max.getBrain().printIdeas();
    
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
