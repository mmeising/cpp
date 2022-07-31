/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:47:18 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/31 17:04:00 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap default constructor called\n";
    name_ = "default_name_clap_name";
    hit_points_ = FragTrap::hit_points_;
    energy_points_ = ScavTrap::energy_points_;
    attack_dmg_ = FragTrap::attack_dmg_;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ScavTrap(src), FragTrap(src) {
    std::cout << "DiamondTrap copy constructor called\n";
    name_ = src.name_;
    hit_points_ = src.hit_points_;
    energy_points_ = src.energy_points_;
    attack_dmg_ = src.attack_dmg_;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) {
    std::cout << "DiamondTrap named constructor called\n";
    name_ = name + "_clap_name";
    hit_points_ = FragTrap::hit_points_;
    energy_points_ = ScavTrap::energy_points_;
    attack_dmg_ = FragTrap::attack_dmg_;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap default destructor called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs) {
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

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "My name is " << name_ << " and I am a DiamondTrap\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************ */