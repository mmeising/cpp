/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:58:20 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/23 20:49:40 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./convert <input to be converted (without angle "
                     "brackets)>\n";
        return (1);
    }
    std::string input(argv[1]);
    std::cout << "input was: " << input << "\n";
    std::cout << "char: " << static_cast<char>(input[0]) << "\n";
    return (0);
}
