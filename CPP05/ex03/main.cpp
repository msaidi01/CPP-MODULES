/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:50:54 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/01 11:52:23 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
int main()
{
    Bureaucrat b("amine", 1);
    
    
    std::cout << "-------------------------" << std::endl;
    try
    {
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
        std::cout << "-------------------------" << std::endl;
    AForm *f;
    Intern i;
    f = i.makeForm("shrubbery creation", "test");
    b.signForm(*f);
    f->execute(b);
    delete f;
        std::cout << "-------------------------" << std::endl;
    f = i.makeForm("robotomy request", "test");
    b.signForm(*f);
    f->execute(b);
    delete f;
        std::cout << "-------------------------" << std::endl;
    f = i.makeForm("presidential pardon", "test");
    b.signForm(*f);
    f->execute(b);
    delete f;

    return 0;
}
