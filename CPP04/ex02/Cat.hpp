/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:00:10 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/03 19:05:58 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
    private:
    Brain* brainCat;
    public:
    Cat();
    Cat(Cat &ob);
    Cat& operator=(Cat &ob);
    ~Cat();


    std::string getType();

    Brain getBrain();
    void setBrain(Brain &ob);
    void makeSound() const;
};


#endif