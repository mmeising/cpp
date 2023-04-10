/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:07:30 by mmeising          #+#    #+#             */
/*   Updated: 2023/04/11 01:55:12 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <typeinfo>

// template <typename T>
// void foo()
// {
//     if (typeid(T) == typeid(animal)) { /* ... */ }
// }

int main(int argc, char** argv) {
    // // std::time_t start;
    // // struct timeval begin;
    // clock_t beginning;

    // // time(&start);
    // // begin.tv_usec;
    // // CLOCKS_PER_SEC;
    // beginning = clock();
    // for (int i = 0; i < 10000; i++);
    // std::cout << "it took " << (float)(clock() - beginning)/CLOCKS_PER_SEC << " seconds" << std::endl;

    PmergeMe test;

    if (argc < 2) {
        std::cout   << "Usage: ./PmergeMe 3 1 2 5 4\n"
                    << "QoL tip (OSX):  /PmergeMe `jot -r 3000 1 100000 | tr '\\n' ' '`\n"
                    << "QoL tip (Unix): /PmergeMe `shuf -i 1-100000 -n 3000 | tr \"\\n\" \" \"`"
                    << std::endl;
    }
    test.sortVector(&(argv[1]));
}
