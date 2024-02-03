/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:35:51 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/03 18:39:23 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
    private:
    std::string ideas[100];
    public:
    Brain();
    Brain(Brain &ob);
    Brain& operator=(Brain &ob);

    void setIdeas(std::string s);
    void printIdeas();
    ~Brain();
};

#endif
