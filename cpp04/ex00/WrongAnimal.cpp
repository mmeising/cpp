/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:18:57 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/10 17:48:27 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal() { std::cout << "Wrong Animal default constructor called\n"; }

WrongAnimal::WrongAnimal(const WrongAnimal& src) {
    std::cout << "Wrong Animal copy constructor called\n";
    type_ = src.type_;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal() { std::cout << "Wrong Animal default destructor called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs) {
    if (this != &rhs) {
        type_ = rhs.type_;
    }
    return *this;
}

// std::ostream& operator<<(std::ostream& o, Animal const& i) {
//     // o << "Value = " << i.getValue();
//     return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongAnimal::makeSound() const {
    std::cout << "I'm a Wrong animal, I don't make a sound\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongAnimal::getType() const { return type_; }

/* ************************************************************************ */