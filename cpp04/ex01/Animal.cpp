/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:18:57 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/01 16:32:21 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() { std::cout << "Animal default constructor called\n"; }

Animal::Animal(const Animal& src) {
    std::cout << "Animal copy constructor called\n";
    type_ = src.type_;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal() { std::cout << "Animal default destructor called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal& Animal::operator=(Animal const& rhs) {
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

void Animal::makeSound() const {
    std::cout << "I'm not a real animal, I don't make a sound\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Animal::getType() const { return type_; }

/* ************************************************************************ */