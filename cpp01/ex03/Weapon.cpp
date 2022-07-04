/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:49:48 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/04 17:24:00 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Weapon::Weapon() {}
Weapon::Weapon(const Weapon& src) : type(src.getType()) {}
Weapon::Weapon(std::string type) : type(type) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Weapon::~Weapon() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Weapon& Weapon::operator=(Weapon const& rhs) {
    if (this != &rhs) {
        type = rhs.getType();
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, Weapon const& i) {
    o << i.getType();
    return o;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const& Weapon::getType() const { return type; }

/*
** --------------------------------- MUTATOR ----------------------------------
*/

void Weapon::setType(std::string const& new_type) { type = new_type; }

/* ************************************************************************** */