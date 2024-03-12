/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:50:54 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/08 19:59:59 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main()
{
    Form f;
    
    std::cout << f << std::endl;
    std::cout << "-------------------------" << std::endl;
    try
    {
        Bureaucrat b("amine", 1);
        Form d("certificat", 150, 15);
        std::cout << d << std::endl;
        std::cout << "-------------------------" << std::endl;
        f.beSigned(b);

        b.signForm(d);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
