/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:37:19 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/26 11:55:43 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
    std::string target;
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm &ob);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm &ob);
    ~ShrubberyCreationForm();
    class FileException : public std::exception
    {
        const char* what() const throw();
    };
    void execute(Bureaucrat const & executor) const;
    
    
    
};

#endif
