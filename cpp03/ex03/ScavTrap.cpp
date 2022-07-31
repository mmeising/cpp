/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:15:37 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/25 17:36:12 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructor called\n";
    name_ = "default_name";
    hit_points_ = 100;
    energy_points_ = 50;
    attack_dmg_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
    std::cout << "ScavTrap copy constructor called\n";
    name_ = src.name_;
    hit_points_ = src.hit_points_;
    energy_points_ = src.energy_points_;
    attack_dmg_ = src.attack_dmg_;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap named constructor called\n";
    name_ = name;
    hit_points_ = 100;
    energy_points_ = 50;
    attack_dmg_ = 20;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap() { std::cout << "ScavTrap default destructor called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {
    if (this != &rhs) {
        this->name_ = rhs.name_;
        this->hit_points_ = rhs.hit_points_;
        this->energy_points_ = rhs.energy_points_;
        this->attack_dmg_ = rhs.attack_dmg_;
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::attack(const std::string& target) {
    if (energy_points_ > 0 && hit_points_ > 0) {
        std::cout << "ScavTrap " << name_ << " attacks " << target
                  << ", causing " << attack_dmg_ << " points of damage\n";
        energy_points_--;
    } else {
        std::cout << name_ << " can't attack " << target;
        std::cout << ", no energy points left\n";
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************ */