/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:37:03 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/01 09:37:22 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>

int main( void )
{
    Fixed a;
    Fixed n (10);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "-----------------------------------" << std::endl;

    std::cout << (n > b) << std::endl;
    std::cout << (n < b) << std::endl;
    
    std::cout << "-----------------------------------" << std::endl;
    
    Fixed m(Fixed::min(n, b));
    std::cout << "min is: " << m << std::endl;
    Fixed z(Fixed::max(n, b));
    std::cout << "max is: " << z << std::endl;
    
    std::cout << "-----------------------------------" << std::endl;
    
    std::cout << (b - n) << std::endl;
    std::cout << (b + n) << std::endl;


    return 0;
}
