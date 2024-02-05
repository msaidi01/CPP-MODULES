/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:34:00 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/05 11:19:58 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    std::cout << "--------------------------------------" << std::endl;

    const WrongAnimal* a = new WrongAnimal();
    const WrongAnimal* b = new WrongCat();
    
    std::cout << a->getType() << " " << std::endl;
    std::cout << b->getType() << " " << std::endl;
    b->makeSound(); //will output the WrongAnimal sound!
    a->makeSound();

    return (delete meta, delete j, delete i, delete a, delete b, 0);
}
