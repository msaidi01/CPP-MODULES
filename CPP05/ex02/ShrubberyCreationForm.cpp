/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:43:32 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/01 09:16:42 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbrery", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &ob) : AForm(ob), target(ob.target)
{
    *this = ob;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &ob)
{
    if (this != &ob)
    {
        this->target = ob.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

const char* ShrubberyCreationForm::FileException::what() const throw()
{
    return "file problem !";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (!this->getSigne())
    {
        throw AForm::notSignedException();
    }
    std::string nameFile = this->target + "_shrubbery";
    std::ofstream file; file.open(nameFile);
    if (!file.is_open() || file.bad() || file.fail())
        throw FileException();
    file << "    /\\\n";
    file << "   /~~\\ \n";
    file << "  /~0~~\\ \n";
    file << " /~~~~0~\\ \n";
    file << " *--||--*\n";
    file << "    ||   \n";
    file.close();
    std::cout << "ASCII tree is drawed in " << nameFile << std::endl;
}