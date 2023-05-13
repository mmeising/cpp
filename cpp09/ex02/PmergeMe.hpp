/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:07:28 by mmeising          #+#    #+#             */
/*   Updated: 2023/05/13 14:58:49 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe {
    typedef std::vector<int>::iterator      vecIter;
    typedef std::vector<std::vector<int> >  vecVec;
    typedef PmergeMe::vecVec::iterator      vecVecIter;

    typedef std::deque<int>::iterator       deqIter;
    typedef std::deque<std::deque<int> >    deqDeq;
    typedef PmergeMe::deqDeq::iterator      deqDeqIter;

   public:
    PmergeMe();
    ~PmergeMe();

    void sortBoth(char** argv);
    void sortDeque(char** argv);
    void printVectors(vecVec all);

   protected:

   private:
    PmergeMe(const PmergeMe& src);
    PmergeMe&           operator=(const PmergeMe& rhs);
    bool                checkInput(char** argv) const;
    std::vector<int>    fillVector(char** argv);
    vecVec              splitVector(std::vector<int> vec);
    vecVec              insertionVector(vecVec& all);
    void                insertionOneVector(std::vector<int>& vec);
    std::vector<int>    mergeVector(vecVec& all);
    std::vector<int>    mergeTwoVecs(std::vector<int> vec1, std::vector<int> vec2);

    std::deque<int>     fillDeque(char** argv);
    deqDeq              splitDeque(std::deque<int> deq);
    deqDeq              insertionDeque(deqDeq& all);
    void                insertionOneDeque(std::deque<int>& deq);
    std::deque<int>     mergeDeque(deqDeq& all);
    std::deque<int>     mergeTwoDeqs(std::deque<int> deq1, std::deque<int> deq2);
};
