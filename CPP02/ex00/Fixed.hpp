/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:37:00 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/01 11:08:20 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP


class Fixed
{
    private:
    int value;
    static const int frac;
    public:
    Fixed();
    Fixed(const Fixed& a);
    Fixed& operator=(const Fixed& a);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    ~Fixed();
};

#endif
