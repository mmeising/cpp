/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:07:25 by mmeising          #+#    #+#             */
/*   Updated: 2023/04/11 01:51:06 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>

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

void PmergeMe::sortVector(char** argv) {
    if (!checkInput(argv))
        return;
    
}
