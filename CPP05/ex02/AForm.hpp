/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:10:22 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/01 09:25:18 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class AForm
{
    private:
    std::string const _name;
    bool _signe;
    const int _gradeToSigne;
    const int _gradeToExecute;
    public:
    AForm();
    AForm(std::string name, int gradeToSigne, int gradeToExecute);
    AForm(AForm const &ob);
    AForm& operator=(AForm const &ob);
    virtual ~AForm();
    class GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };
    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };
    class notSignedException : public std::exception
    {
        const char* what() const throw();
    };
    std::string getName() const;
    bool getSigne() const;
    int getGradeToSigne() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat const &ob);
    
    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& a);

#endif
