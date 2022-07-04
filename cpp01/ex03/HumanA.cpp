/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 04:54:11 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/04 18:34:36 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanA::HumanA(const HumanA& src) : name(src.name), weapon(src.weapon) {}
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanA::~HumanA() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

HumanA& HumanA::operator=(HumanA const& rhs) {
    if (this != &rhs) {
        name = rhs.name;
        weapon = rhs.weapon;
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon << "\n";
}

/* ************************************************************************* */