/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:50:54 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/23 19:10:12 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main()
{
    Bureaucrat a;

    std::cout << a << std::endl;

    try
    {
        Bureaucrat b("mrda", 50);
        b.incGrade();
        b.incGrade();
        b.incGrade();
        std::cout << b << std::endl;
        std::cout << a << std::endl;
        a.decGrade();
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
