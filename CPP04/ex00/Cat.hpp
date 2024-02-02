/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:00:10 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/02 18:11:49 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
    protected:
    std::string type;
    public:
    Cat();
    Cat(Cat &ob);
    Cat& operator=(Cat &ob);

    void setType(std::string type);
    std::string getType();
    
    ~Cat();

    
};


#endif