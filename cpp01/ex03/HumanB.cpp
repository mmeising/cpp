/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 04:55:36 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/04 18:34:54 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

HumanB::HumanB() : name("default name"), weapon(NULL) {}
HumanB::HumanB(const HumanB& src) : name(src.name), weapon(src.weapon) {}
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

HumanB::~HumanB() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

HumanB& HumanB::operator=(HumanB const& rhs) {
    if (this != &rhs) {
        name = rhs.name;
        weapon = rhs.weapon;
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void HumanB::attack() {
    std::cout << name << " attacks with their ";
    if (weapon->getType() != "") {
        std::cout << weapon->getType() << "\n";
    } else {
        std::cout << "bare fists\n";
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void HumanB::setWeapon(Weapon& new_weapon) { weapon = &new_weapon; }

/*
** --------------------------------- MUTATOR ----------------------------------
*/

Weapon* HumanB::getWeapon() { return weapon; }

/* ************************************************************************* */