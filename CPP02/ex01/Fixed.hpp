/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:37:00 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/31 11:17:02 by msaidi           ###   ########.fr       */
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
    Fixed& operator=(const Fixed& a);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
    ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& a);



#endif