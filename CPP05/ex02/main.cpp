/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:50:54 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/08 19:57:44 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
int main()
{
    try
    {
        Bureaucrat b("amine", 1);
        ShrubberyCreationForm f("test");
        b.signForm(f);
        f.execute(b);
        std::cout << "-------------------------" << std::endl;
        RobotomyRequestForm robot;
        robot.beSigned(b);
        robot.execute(b);
        std::cout << "-------------------------" << std::endl;
        PresidentialPardonForm Pr;
        Pr.beSigned(b);
        Pr.execute(b);
        std::cout << "-------------------------" << std::endl;
        PresidentialPardonForm sry("Jordan");
        sry.beSigned(b);
        b.executeForm(sry);
        
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
