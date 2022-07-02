/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 23:21:58 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/03 00:01:20 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Zombie::Zombie() { std::cout << "Default constructor called\n"; }

Zombie::Zombie(std::string new_name) : name(new_name) {
    std::cout << name << " named constructor called\n";
}

Zombie::Zombie(const Zombie& src) : name(src.name) {
    std::cout << src.name << " copy constructor called\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Zombie::~Zombie() { std::cout << name << " destroyed\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Zombie& Zombie::operator=(Zombie const& rhs) {
    if (this != &rhs) {
        name = rhs.name;
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Zombie::announce(void) { std::cout << name << ": BraiiiiiiinnnzzzZ...\n"; }
void Zombie::setName(std::string new_name) { name = new_name; }

/* ************************************************************************** */