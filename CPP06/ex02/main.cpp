/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:08:11 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/11 18:45:07 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

typedef struct cc 
{
    int A;
    int B;
    int C;  
}cc_t;

int main()
{
    // Base *base = generate();
    cc_t *A = new cc_t;
    A->A = 1;
    A->B = 2;
    A->C = 3;
    int *re = reinterpret_cast<int *>(A);
    std::cout << re[0] << std::endl;
    std::cout << re[1] << std::endl;
    
    
    return 0;
}