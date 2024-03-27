/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:08:48 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/25 23:43:00 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <vector>
#include <iostream>


int main()
{
    std::vector<int> container;
    container.push_back(42);
    container.push_back(56);
    container.push_back(78);
    container.push_back(90);
    container.push_back(100);

    std::cout << "vector container : " << *easyfind(container, 78) << std::endl;

    std::array<int, 7> arr = {1, 2, 3, 4, 5, 6, 7};
    
    std::cout << "array container : " << *easyfind(arr, 4) << std::endl;

    return 0;
}