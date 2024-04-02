/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:18:00 by msaidi            #+#    #+#             */
/*   Updated: 2024/04/02 05:53:50 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <utility>
#include <vector>

class PmergeMevec
{
    private:
        std::vector<int> vecSorted;
        int strug;
        double time;
    public:
        PmergeMevec();
        PmergeMevec(const PmergeMevec &p);
        ~PmergeMevec();
        PmergeMevec &operator=(const PmergeMevec &p);

        void setStrug(int s);
        int getStrug() const;
        void setTime(double t);
        double getTime();
        std::vector<int> &getVecSorted();
        void mergeSort(std::vector<std::pair<int, int> > &pairs);
        int createPairs(char **av);
        void printVec();
};
class PmergeMedeq
{
    private:
        std::deque<int> deqSorted;
        int strug;
        double time;
    public:
        PmergeMedeq();
        PmergeMedeq(const PmergeMedeq &p);
        ~PmergeMedeq();
        PmergeMedeq &operator=(const PmergeMedeq &p);

        void setStrug(int s);
        int getStrug() const;
        void setTime(double t);
        double getTime();
        std::deque<int> &getDeqSorted();
        void mergeSortdeq(std::deque<std::pair<int, int> > &pairs);
        int createPairsdeq(char **av);
};






#endif