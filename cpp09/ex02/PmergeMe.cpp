/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:07:25 by mmeising          #+#    #+#             */
/*   Updated: 2023/05/12 22:28:10 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}


PmergeMe::PmergeMe(const PmergeMe& src) {
    (void)src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    (void)rhs;
    return (*this);
}

/**
 * @returns true on success, false on failure
*/
bool PmergeMe::checkInput(char** argv) const {
    double val;

    while (*argv) {
        std::string       str(*argv);
        std::stringstream ss(*argv);

        ss >> val;
        if (val > 2147483647 || val < 0
            || str.find_first_not_of("0123456789") != std::string::npos) {
            std::cerr << "Input must be positive integers only, no signs in input" << std::endl;
            return (false);
        }
        argv++;
    }
    return (true);
}

void    printVector(std::vector<int> vec) {
    std::vector<int>::const_iterator it = vec.begin();

    while (it != vec.end()) {
        std::cout << *it << ", ";
        it++;
    }
    std::cout << std::endl;
}

void    PmergeMe::printVectors(PmergeMe::vecVec all) {
    PmergeMe::vecVecIter it = all.begin();
    int i = 0;
    while (it != all.end()) {
        std::cout << i++ << ": ";
        printVector(*it);
        it++;
    }
}

std::vector<int> PmergeMe::fillVector(char** argv) {
    std::vector<int>    vec;
    while (*argv) {
        std::stringstream ss(*argv);
        int               val;

        ss >> val;
        vec.push_back(val);
        argv++;
    }
    return (vec);
}

PmergeMe::vecVec PmergeMe::splitVector(std::vector<int> vec) {
    PmergeMe::vecVec all;

    while (vec.size() > 10) {
        PmergeMe::vecIter   vec_begin = vec.begin();
        std::vector<int>    part(vec_begin, vec_begin + 10);

        vec.erase(vec_begin, vec_begin + 10);
        part.reserve(11);
        all.push_back(part);
    }
    all.push_back(vec);
    vec.clear();
    return (all);
}

void PmergeMe::insertionOneVector(std::vector<int>& vec) {
    PmergeMe::vecIter it;
    PmergeMe::vecIter ite = vec.begin();

    ite++;
    while (ite != vec.end()) {//cycling through entries of one vector
        it = vec.begin();
        while (it != ite) {
            if (*ite < *it) {
                int x = *ite;
                vec.erase(ite);
                vec.insert(it, x);//inserts value of ite before it position
                break;
            }
            it++;
        }
        ite++;
    }
}

PmergeMe::vecVec PmergeMe::insertionVector(PmergeMe::vecVec& all) {
    vecVecIter it_all = all.begin();

    while (it_all != all.end()) {//cycling through all the vectors
        insertionOneVector(*it_all);
        it_all++;
    }
    return (all);
}

std::vector<int> PmergeMe::mergeTwoVecs(std::vector<int> vec1, std::vector<int> vec2) {
    PmergeMe::vecIter   it1;
    PmergeMe::vecIter   it2;
    std::vector<int>    ret;


    ret.reserve(vec1.size() + vec2.size());
    it1 = vec1.begin();
    it2 = vec2.begin();
    while (it1 != vec1.end() && it2 != vec2.end()) {
        if (*it1 < *it2) {
            ret.push_back(*it1);
            it1++;
        } else {
            ret.push_back(*it2);
            it2++;
        }
    }
    while (it1 != vec1.end()) {
        ret.push_back(*it1);
        it1++;
    }
    while (it2 != vec2.end()) {
        ret.push_back(*it2);
        it2++;
    }
    return (ret);
}

std::vector<int> PmergeMe::mergeVector(PmergeMe::vecVec& all) {
    PmergeMe::vecVec all_2;

    while (all.size() > 1) {
        all_2 = all;
        all.clear();
        PmergeMe::vecVecIter ite = all_2.begin();
        while (ite != all_2.end() && ++ite != all_2.end()) {
            ite = all_2.begin();
            all.push_back(mergeTwoVecs(*ite, *(++ite)));
            all_2.erase(all_2.begin());
            all_2.erase(all_2.begin());
            ite = all_2.begin();
        }
        if (all_2.size() > 0)
            all.push_back(*(all_2.begin()));
        all_2.clear();
    }
    return (*(all.begin()));
}

void PmergeMe::sortVector(char** argv) {
    std::vector<int>    vec;
    PmergeMe::vecVec   all;
    clock_t             t = clock();

    if (!checkInput(argv))
        return;
    vec = fillVector(argv);
    all = splitVector(vec);
    insertionVector(all);
    vec = mergeVector(all);
    printVector(vec);
    t = clock() - t;
    printf("sortVector took %lu clicks, %f seconds (%d clocks per second)\n", t, ((float)t) / CLOCKS_PER_SEC, CLOCKS_PER_SEC);
}
