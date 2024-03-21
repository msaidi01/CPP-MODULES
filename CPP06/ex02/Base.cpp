/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:07:19 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/21 01:07:29 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>


Base::~Base()
{}

Base *generate(void)
{
    std::srand(time(0));
    int i = rand() % 3;
    if (i == 1)
        return new A();
    else if (i == 2)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Invalid Type" << std::endl;
}

void identify(Base& p)
{
        A a;
        B b;
        C c;

    try
    {
        a = dynamic_cast<A&>(p);
        std::cout << "Type is A" << std::endl;
    }
    catch(std::exception &e)
    {
        try
        {
            b = dynamic_cast<B&>(p);
            std::cout << "Type is B" << std::endl;
        }
        catch(std::exception &e)
        {
            try
            {
                c = dynamic_cast<C&>(p);  
                std::cout << "Type is C" << std::endl;
                
            }
            catch(std::exception &e)
            {
                std::cout << "Invalid type!" << std::endl;
            }
        }
    }
}
