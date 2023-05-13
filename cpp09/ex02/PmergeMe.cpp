/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:07:25 by mmeising          #+#    #+#             */
/*   Updated: 2023/05/13 14:53:19 by mmeising         ###   ########.fr       */
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
    std::vector<int>::size_type size = 100;

    while (vec.size() > size) {
        PmergeMe::vecIter   vec_begin = vec.begin();
        std::vector<int>    part(vec_begin, vec_begin + size);

        vec.erase(vec_begin, vec_begin + size);
        part.reserve(size + 1);
        all.push_back(part);
    }
    all.push_back(vec);
    vec.clear();
    return (all);
}

void PmergeMe::insertionOneVector(std::vector<int>& vec) {
    PmergeMe::vecIter it = vec.begin();
    PmergeMe::vecIter ite = it;

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

/*
***     DEQUE STARTING HERE
*/

std::deque<int> PmergeMe::fillDeque(char** argv) {
    std::deque<int>    deq;
    while (*argv) {
        std::stringstream ss(*argv);
        int               val;

        ss >> val;
        deq.push_back(val);
        argv++;
    }
    return (deq);
}

PmergeMe::deqDeq PmergeMe::splitDeque(std::deque<int> deq) {
    PmergeMe::deqDeq all;
    std::deque<int>::size_type size = 2;

    while (deq.size() > size) {
        PmergeMe::deqIter   vec_begin = deq.begin();
        std::deque<int>    part(vec_begin, vec_begin + size);

        deq.erase(vec_begin, vec_begin + size);
        all.push_back(part);
    }
    all.push_back(deq);
    deq.clear();
    return (all);
}

void PmergeMe::insertionOneDeque(std::deque<int>& deq) {
    PmergeMe::deqIter it = deq.begin();
    PmergeMe::deqIter ite = it;

    ite++;
    if (ite != deq.end() && *ite < *it) {
        std::swap(*ite, *it);
    }
}

PmergeMe::deqDeq PmergeMe::insertionDeque(PmergeMe::deqDeq& all) {
    deqDeqIter it_all = all.begin();

    while (it_all != all.end()) {//cycling through all the deques
        insertionOneDeque(*it_all);
        it_all++;
    }
    return (all);
}

std::deque<int> PmergeMe::mergeTwoDeqs(std::deque<int> vec1, std::deque<int> vec2) {
    PmergeMe::deqIter   it1;
    PmergeMe::deqIter   it2;
    std::deque<int>    ret;

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

std::deque<int> PmergeMe::mergeDeque(PmergeMe::deqDeq& all) {
    PmergeMe::deqDeq all_2;

    while (all.size() > 1) {
        all_2 = all;
        all.clear();
        PmergeMe::deqDeqIter ite = all_2.begin();
        while (ite != all_2.end() && ++ite != all_2.end()) {
            ite = all_2.begin();
            all.push_back(mergeTwoDeqs(*ite, *(++ite)));
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

void PmergeMe::sortBoth(char** argv) {
    std::vector<int>    vec;

    if (!checkInput(argv))
        return;
    vec = fillVector(argv);
    std::cout << "Before:\t";
    printVector(vec);
    vec.clear();

/*  VECTOR  */

    PmergeMe::vecVec    all_vec;
    clock_t             t_vector;

    t_vector = clock();
    vec = fillVector(argv);
    all_vec = splitVector(vec);
    insertionVector(all_vec);
    vec = mergeVector(all_vec);
    t_vector = clock() - t_vector;

    std::cout << "\nAfter: ";
    printVector(vec);

/*  DEQUE   */

    std::deque<int>     deq;
    PmergeMe::deqDeq    all_deq;
    clock_t             t_deque;

    t_deque = clock();
    deq = fillDeque(argv);
    all_deq = splitDeque(deq);
    insertionDeque(all_deq);
    deq = mergeDeque(all_deq);
    t_deque = clock() - t_deque;

    // std::cout << "\nAfter: ";
    // for (size_t i = 0; i < deq.size(); i++) {
    //     std::cout << deq[i] << ", ";
    // }
    // std::cout << std::endl;

/*  VECTOR  */
    std::cout   << "Time to process a range of\t"
                << vec.size() << " elements with std::vector:\t"
                << ((float)t_vector) / CLOCKS_PER_SEC << " seconds" << std::endl;

/*  DEQUE   */
    std::cout   << "Time to process a range of\t"
                << deq.size() << " elements with std::deque:\t"
                << ((float)t_deque) / CLOCKS_PER_SEC << " seconds" << std::endl;
}
