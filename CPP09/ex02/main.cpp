/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:17:54 by msaidi            #+#    #+#             */
/*   Updated: 2024/04/02 07:03:20 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <ctime>
#include <iostream>
#include "PmergeMe.hpp"
#include <cstdlib>
#include <ostream>

bool CheckArg(char **av)
{
    for (int i = 1 ; av[i] ; i++ )
	{
		std::string str(av[i]);
		if (str.empty())
			return false;
		long long nbr(strtol(av[i], NULL, 10));
		if (nbr < 0 || INT_MAX < nbr)
			return false;
		for (int j = 0 ; av[i][j]; j++)
			if (!isdigit(av[i][j]))
				return false;
	}
	return true;
}



int main(int ac, char **av)
{
    if (ac < 2 || !CheckArg(av))
    {
        std::cout << "Invalid input." << std::endl;
        return 0;
    }
	PmergeMevec vec;
	if (vec.createPairs(av)){
		std::cout << "Time to process a range of " <<  1 << "  elements with std::vector : " << vec.getTime() << "us" << std::endl;
	}
	
	PmergeMedeq deq;
	if (deq.createPairsdeq(av)){
		std::cout << "Time to process a range of " << 1 << "  elements with std::deque : " << deq.getTime() << "us" << std::endl;
		return 0;
	}
	
	
	std::cout << "Before : ";
	for (int i = 1; i < ac; i++){
		std::cout << av[i] << " ";
	}
	std::cout << std::endl;
	vec.printVec();
	std::cout << "Time to process a range of " << ac - 1 << "  elements with std::vector : " << vec.getTime() << "us" << std::endl;
	std::cout << "Time to process a range of " << ac - 1 << "  elements with std::deque : " << deq.getTime() << "us" << std::endl;
	
}
