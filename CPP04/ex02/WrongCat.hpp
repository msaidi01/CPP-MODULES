/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:33:04 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/03 13:33:53 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
    public:
    WrongCat();
    WrongCat(WrongCat &ob);
    WrongCat& operator=(WrongCat &ob);
    ~WrongCat();


    std::string getType();
    void makeSound() const;
};


#endif