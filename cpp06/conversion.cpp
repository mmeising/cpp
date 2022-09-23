/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:37:25 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/23 21:28:04 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

void printAsChar(std::string input) {
    char c;

    if (input.length() != 1) {
        std::cout << "Non displayable\n";
        return;
    }
    c = static_cast<char>(input[0]);
    if (c >= 32 && c <= 126)
        std::cout << c << "\n";
    else
        std::cout << "Non displayable\n";
}

bool CheckIfNumber(std::string input) {
    int i = 0;
    bool dot = false;
    char c;

    while (input[i]) {
        c = input[i];
        if (c == 'f' && input.length() == i + 1)
            return (true);
        else if (c == '.' &&
                 (dot == true || input.length() == i + 1 ||
                 !(input[i + 1] >= '0' && input[i + 1] <= '9')))
            return (false);
        else if (c == '.')
            dot = true;
        else if ( (c == '-' || c == '+') && i != 0)
            return (false);
        else if (!(c >= '0' && c <= '9') &&
                   c != '.' && c != '-' && c != '+')
    }
}

void printAsInt(std::string input) {
    int x;

    if (CheckIfNumber(input))
        //print it
    else
        //print "impossible"
}

void printAsFloat(std::string input);
void printAsDouble(std::string input);