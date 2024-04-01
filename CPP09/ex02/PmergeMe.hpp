/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:18:00 by msaidi            #+#    #+#             */
/*   Updated: 2024/04/01 04:51:47 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <utility>
#include <vector>

class PmergeMe
{
    private:
        int strug;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &p);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &p);

        void setStrug(int s);
        int getStrug() const;
        void createPairs(std::vector<int> &v);
        void merge(std::vector<std::pair<int, int> > &pairs);
};






#endif