/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:50:54 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/08 20:00:28 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
    AForm *f;
    AForm *f1;
    AForm *f2;
    Intern i;
    f = i.makeForm("shrubbery creation", "test");
    f1 = i.makeForm("robotomy request", "test");
    f2 = i.makeForm("presidential pardon", "test");
    try
    {
        Bureaucrat b("amine", 500);
        b.signForm(*f);
        f->execute(b);
            std::cout << "-------------------------" << std::endl;
        b.signForm(*f1);
        f1->execute(b);
            std::cout << "-------------------------" << std::endl;
        b.signForm(*f2);
        f2->execute(b);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    delete f;
    delete f1;
    delete f2;
    return 0;
}
