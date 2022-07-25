/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:56:31 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/25 15:44:45 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap()
    : name_("default_name"),
      hit_points_(10),
      energy_points_(10),
      attack_dmg_(0) {
    std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& src)
    : name_(src.name_),
      hit_points_(src.hit_points_),
      energy_points_(src.energy_points_),
      attack_dmg_(src.attack_dmg_) {
    std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap::ClapTrap(std::string name)
    : name_(name), hit_points_(10), energy_points_(10), attack_dmg_(0) {
    std::cout << "ClapTrap named constructor called\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap() { std::cout << "ClapTrap default destructor called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {
    if (this != &rhs) {
        this->name_ = rhs.name_;
        this->hit_points_ = rhs.hit_points_;
        this->energy_points_ = rhs.energy_points_;
        this->attack_dmg_ = rhs.attack_dmg_;
    }
    return *this;
}

// std::ostream& operator<<(std::ostream& o, ClapTrap const& i) {
//     // o << "Value = " << i.getValue();
//     return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack(const std::string& target) {
    if (energy_points_ > 0 && hit_points_ > 0) {
        std::cout << "ClapTrap " << name_ << " attacks " << target
                  << ", causing " << attack_dmg_ << " points of damage\n";
        energy_points_--;
    } else {
        std::cout << name_ << " can't attack " << target;
        std::cout << ", no energy points left\n";
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hit_points_ > 0) {
        hit_points_ -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energy_points_ > 0 && hit_points_ > 0) {
        std::cout << name_ << " repaired itself and gained " << amount
                  << "hit points\n";
        energy_points_--;
    } else {
        std::cout << name_ << " can't repair itself, no energy points left\n";
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************ */