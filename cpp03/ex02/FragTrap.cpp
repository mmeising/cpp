/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:06:13 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/31 15:09:23 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor called\n";
    name_ = "default_name";
    hit_points_ = 100;
    energy_points_ = 100;
    attack_dmg_ = 30;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
    std::cout << "FragTrap copy constructor called\n";
    name_ = src.name_;
    hit_points_ = src.hit_points_;
    energy_points_ = src.energy_points_;
    attack_dmg_ = src.attack_dmg_;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap named constructor called\n";
    name_ = name;
    hit_points_ = 100;
    energy_points_ = 100;
    attack_dmg_ = 30;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap() { std::cout << "FragTrap default destructor called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap& FragTrap::operator=(FragTrap const& rhs) {
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

void FragTrap::attack(const std::string& target) {
    if (energy_points_ > 0 && hit_points_ > 0) {
        std::cout << "FragTrap " << name_ << " attacks " << target
                  << ", causing " << attack_dmg_ << " points of damage\n";
        energy_points_--;
    } else {
        std::cout << name_ << " can't attack " << target;
        std::cout << ", no energy points left\n";
    }
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name_ << ": \"High fives everyone!\"\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************ */