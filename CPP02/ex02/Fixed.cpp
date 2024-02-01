/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:36:53 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/31 18:59:32 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::frac = 8;

Fixed::Fixed(): value(0)
{}

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
	*this = a;
}

Fixed& Fixed::operator=(const Fixed& a)
{
	value = a.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
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
{}

bool Fixed::operator>(const Fixed& a) const
{
	return this->value > a.value;
}
bool Fixed::operator>=(const Fixed& a) const
{
	return this->value >= a.value;
}

bool Fixed::operator<(const Fixed& a) const
{
	return this->value < a.value;
}

bool Fixed::operator<=(const Fixed& a) const
{
	return this->value <= a.value;
}

bool Fixed::operator==(const Fixed& a) const
{
	return this->value == a.value;
}
bool Fixed::operator!=(const Fixed& a) const
{
	return this->value != a.value;
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
}
Fixed Fixed::operator+(const Fixed& a) const
{
	Fixed sum;
	
	sum.setRawBits(this->getRawBits() + a.getRawBits());
	return sum;
}

Fixed Fixed::operator-(const Fixed& a) const
{
	Fixed sum;
	
	sum.setRawBits(this->getRawBits() - a.getRawBits());
	return sum;
}

Fixed Fixed::operator*(const Fixed& a) const
{
	Fixed sum;

	sum.setRawBits((this->getRawBits() * a.getRawBits()) * 1 >> frac);
	return sum;
}

Fixed Fixed::operator/(const Fixed& a) const
{
	Fixed sum;

	sum.setRawBits((this->getRawBits() / a.getRawBits()) * 1 << frac);
	return sum;
}

Fixed& Fixed::operator++()
{
	this->value++;
	return *this;
}
Fixed& Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed obj(*this);
	
	this->value++;
	return obj;
}
Fixed Fixed::operator--(int)
{
	Fixed obj (*this);
	
	this->value--;
	return obj;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.value < b.value)
		return a;
	else
	 return b;
}
Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.value < b.value)
		return (Fixed&)a;
	else
	 return (Fixed&)b;
}
Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.value > b.value)
		return (Fixed&)a;
	else
	 return (Fixed&)b;
}
Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.value > b.value)
		return a;
	else
	 return b;
}
