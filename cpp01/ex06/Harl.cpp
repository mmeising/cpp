/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:24:18 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/06 20:29:56 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- PUBLIC -----------------------------------
*/

void Harl::complain(std::string level) const {
    std::string string_array[4] = {"DEBUG",
                                   "INFO",
                                   "WARNING",
                                   "ERROR"};
    void (Harl::*function_array[4])() const = {&Harl::debug,
                                               &Harl::info,
                                               &Harl::warning,
                                               &Harl::error};
    int i = 0;

    while (level != string_array[i] && ++i < 4)
        ;
    switch (i) {
        case 0:
            (this->*function_array[0])();
        case 1:
            (this->*function_array[1])();
        case 2:
            (this->*function_array[2])();
        case 3:
            (this->*function_array[3])();
            break;
        default:
            std::cout
                << "[ Probably complaining about insignificant problems ]\n\n";
            break;
    }
}

/*
** --------------------------------- PRIVATE ----------------------------------
*/

void Harl::debug() const {
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
                 "really do!\n\n";
}

void Harl::info() const {
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You "
                 "didn’t put enough bacon in my burger! If you did, I wouldn’t "
                 "be asking for more!\n\n";
}

void Harl::warning() const {
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve "
                 "been coming for years whereas you started working here since "
                 "last month.\n\n";
}

void Harl::error() const {
    std::cout << "[ ERROR ]\n";
    std::cout
        << "This is unacceptable! I want to speak to the manager now.\n\n";
}

/* ************************************************************************ */