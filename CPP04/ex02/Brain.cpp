/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:35:46 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/03 18:39:25 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(Brain &ob)
{
    if (this != &ob)
        *this = ob;
}

Brain& Brain::operator=(Brain &ob)
{
    if (this != &ob){
        for (int i = 0; i < 100; i++)
            this->ideas[i] = ob.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

void Brain::setIdeas(std::string s)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = s;
}
void Brain::printIdeas()
{
    for (int i = 0; i < 100; i++)
        std::cout << this->ideas[i] << ", ";
    std::cout << std::endl;
}