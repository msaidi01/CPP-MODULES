/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:36:53 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/31 15:29:47 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::frac = 8;

Fixed::Fixed(): value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    this->value = n * (1 << frac);
}
Fixed::Fixed(const float n)
{
    this->value = roundf(n * (1 << frac));
}

Fixed::Fixed(const Fixed& a)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
}

Fixed& Fixed::operator=(const Fixed& a)
{
    std::cout << "Copy assignment operator called" << std::endl;
    value = a.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->value / (float)(1 << frac));
}

int Fixed::toInt( void ) const
{
    return ((int)this->value / (1 << frac));
}

std::ostream& operator<<(std::ostream& os, const Fixed& a)
{
    os << a.toFloat();
    return os;
}


Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

