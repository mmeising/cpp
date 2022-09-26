/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:37:25 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/26 13:46:05 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.hpp"

/******************************************************************************/
/*                                CHECKS                                      */
/******************************************************************************/

bool isNanOrInf(std::string& input) {
    if (input == "nan" || input == "nanf") {
        input = "nan";
        return (true);
    } else if (input == "+inf" || input == "+inff") {
        input = "+inf";
        return (true);
    } else if (input == "-inf" || input == "-inff") {
        input = "-inf";
        return (true);
    } else
        return (false);
}

bool isNanOrInfFloat(std::string& input) {
    if (input == "nan" || input == "nanf") {
        input = "nanf";
        return (true);
    } else if (input == "+inf" || input == "+inff") {
        input = "+inff";
        return (true);
    } else if (input == "-inf" || input == "-inff") {
        input = "-inff";
        return (true);
    } else
        return (false);
}

bool CheckIfNum(std::string input) {
    unsigned int i = 0;
    bool dot = false;
    char c;

    while (input[i]) {
        c = input[i];
        if (c == 'f' && input.length() == i + 1)
            return (true);
        else if (c == '.' && (dot == true || input.length() == i + 1 ||
                              !(input[i + 1] >= '0' && input[i + 1] <= '9')))
            return (false);
        else if (c == '.')
            dot = true;
        else if ((c == '-' || c == '+') &&
                 (i != 0 || !(input[1] >= '0' && input[1] <= '9')))
            return (false);
        else if (!(c >= '0' && c <= '9') && c != '.' && c != '-' && c != '+')
            return (false);
        i++;
    }
    return (true);
}

/******************************************************************************/
/*                                   PRINTS                                   */
/******************************************************************************/

void printAsChar(std::string input) {
    double x;

    if (CheckIfNum(input)) {
        x = std::atoi(input.c_str());
        if (x >= 32 && x <= 126)
            std::cout << '\'' << x << '\'';
        else
            std::cout << "Non displayable";
    } else if (isNanOrInf(input) || isNanOrInfFloat(input))
        std::cout << "impossible";
    else
        std::cout << "Non displayable";
}

void printAsInt(std::string input) {
    double x;

    if (CheckIfNum(input)) {
        x = std::atof(input.c_str());
        if (x <= std::numeric_limits<int>::max() &&
            x >= std::numeric_limits<int>::min())
            std::cout << static_cast<int>(x);
        else
            std::cout << "impossible";
    } else
        std::cout << "impossible";
}

void printAsFloat(std::string input) {
    float x;

    if (isNanOrInfFloat(input)) {
        std::cout << input;
    } else if (CheckIfNum(input)) {
        x = static_cast<float>(std::atof(input.c_str()));
        std::cout << x;
        if (x - static_cast<int>(x) == 0) {
            std::cout << ".0f";
        } else
            std::cout << "f";
    } else
        std::cout << "impossible";
}

void printAsDouble(std::string input) {
    double x;

    if (isNanOrInf(input)) {
        std::cout << input;
    } else if (CheckIfNum(input)) {
        x = static_cast<double>(std::atof(input.c_str()));
        std::cout << x;
        if (x <= std::numeric_limits<int>::max() &&
            x >= std::numeric_limits<int>::min() &&
            x - static_cast<int>(x) == 0) {
            std::cout << ".0";
        }
    } else
        std::cout << "impossible";
}
