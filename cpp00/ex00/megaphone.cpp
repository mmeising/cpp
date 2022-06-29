/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:52:23 by mmeising          #+#    #+#             */
/*   Updated: 2022/06/29 23:56:51 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string str_toupper(std::string input) {
    for (size_t i = 0; i < input.size(); i++) {
        input[i] = std::toupper(input[i]);
    }
    return (input);
}

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    for (size_t i = 1; argv[i]; i++) {
        std::cout << str_toupper(argv[i]);
    }
    std::cout << "\n";
    return (0);
}
