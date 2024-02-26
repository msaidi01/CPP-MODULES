/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:10:22 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/24 16:43:45 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Form
{
    private:
    std::string const _name;
    bool _signe;
    const int _gradeToSigne;
    const int _gradeToExecute;
    public:
    Form();
    Form(std::string name, int gradeToSigne, int gradeToExecute);
    Form(Form &ob);
    Form& operator=(Form &ob);
    ~Form();
    class GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };
    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };
    std::string getName() const;
    bool getSigne() const;
    int getGradeToSigne() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat &ob);
};

std::ostream& operator<<(std::ostream& os, const Form& a);

#endif
