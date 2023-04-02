/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:14:41 by mmeising          #+#    #+#             */
/*   Updated: 2023/04/02 21:58:25 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

// int main() {
//     std::string input = "9 2 + 4 5 6 * 2 -";
//     std::vector<std::string> inputs;
    
//     std::stringstream ss(input);
//     std::string token;
//     while (ss >> token) {
//         inputs.push_back(token);
//     }
    
//     for (size_t i = 0; i < inputs.size(); i++) {
//         std::cout << inputs[i];
//     }
    
//     return 0;
// }

int main(int argc, char** argv) {
    std::string part;
    RPN         calc;

    if (argc != 2) {
        std::cout << "Usage example: ./RPN \"4 2 - 1 *\"" << std::endl;
        return (1);
    }

    std::stringstream ss(argv[1]);
    while (ss >> part) {
        if (!calc.input(part))
            return (1);
    }
    calc.getResult();
    return (0);
}
