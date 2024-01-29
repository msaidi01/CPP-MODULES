/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 04:40:50 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/25 22:50:08 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>


class Zombie
{
    private:
    std::string name;
    public:
    Zombie();
    void setName(std::string name);
    void announce(void);
    ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );