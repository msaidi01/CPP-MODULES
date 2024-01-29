/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:51:21 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/28 14:54:59 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
    private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    public:
    void complain(std::string level);
};

#endif