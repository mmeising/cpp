/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:07:28 by mmeising          #+#    #+#             */
/*   Updated: 2023/05/12 22:19:24 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

// template <typename T>
// void foo()
// {
//     if (typeid(T) == typeid(animal)) { /* ... */ }
// }

class PmergeMe {
    typedef std::vector<int>::iterator     vecIter;
    typedef std::vector<std::vector<int> > vecVec;
    typedef PmergeMe::vecVec::iterator     vecVecIter;

   public:
    PmergeMe();
    ~PmergeMe();

    void sortVector(char** argv);
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
};
