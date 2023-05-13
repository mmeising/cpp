/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:07:30 by mmeising          #+#    #+#             */
/*   Updated: 2023/05/13 15:24:44 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <typeinfo>

int main(int argc, char** argv) {
    PmergeMe test;

    if (argc < 2) {
        std::cout   << "Usage: ./PmergeMe 3 1 2 5 4\n"
                    << "QoL tip (OSX):  ./PmergeMe `jot -r 3000 1 100000 | tr '\\n' ' '`\n"
                    << "QoL tip (Unix): ./PmergeMe `shuf -i 1-100000 -n 3000 | tr \"\\n\" \" \"`"
                    << std::endl;
        return (1);
    }
    test.sortBoth(&(argv[1]));
}
