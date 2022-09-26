/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:58:20 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/26 13:43:34 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "conversion.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./convert <input to be converted (without angle "
                     "brackets)>\n";
        return (1);
    }
    std::string input(argv[1]);

    std::cout << "char: ";
    printAsChar(input);
    std::cout << "\n";

    std::cout << "int: ";
    printAsInt(input);
    std::cout << "\n";

    std::cout << "float: ";
    printAsFloat(input);
    std::cout << "\n";

    std::cout << "double: ";
    printAsDouble(input);
    std::cout << "\n";
    return (0);
}
