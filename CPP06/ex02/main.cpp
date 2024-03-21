/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:08:11 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/21 01:08:22 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
    Base *base = generate();
    std::cout << "identify a ptr : ";
    identify(base);
    
    std::cout << std::endl << "------------------------" << std::endl;
    
    Base *d = new B;
    std::cout << "identify a ref : ";
    identify(d);

    delete base;
    delete d;
    return 0;
}
