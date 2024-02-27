/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:50:54 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/26 18:48:57 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
    Bureaucrat a("ss", 1);
    

    std::cout << a << std::endl;

    try
    {
        Bureaucrat b("mrda", 1);
        b.incGrade();
        b.incGrade();
        b.incGrade();
        std::cout << b << std::endl;
        std::cout << a << std::endl;
        a.decGrade();
        std::cout<<b.getGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
