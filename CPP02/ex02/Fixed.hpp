/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:37:00 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/01 09:26:25 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>


class Fixed
{
    private:
    int value;
    static const int frac;
    public:
    Fixed();
    Fixed(const Fixed& a);
    Fixed(const int n);
    Fixed(const float n);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
    static Fixed& min(Fixed &a, Fixed &b);
    static Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static Fixed& max(const Fixed &a, const Fixed &b);

    Fixed& operator=(const Fixed& a);
    bool operator>(const Fixed& a) const;
    bool operator>=(const Fixed& a) const;
    bool operator<(const Fixed& a) const;
    bool operator<=(const Fixed& a) const;
    bool operator==(const Fixed& a) const;
    bool operator!=(const Fixed& a) const;
    
    Fixed operator+(const Fixed& a) const;
    Fixed operator-(const Fixed& a) const;
    Fixed operator*(const Fixed& a) const;
    Fixed operator/(const Fixed& a) const;
    
    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);
    

    
    ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& a);



#endif