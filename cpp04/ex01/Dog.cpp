/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:30:57 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/10 15:38:42 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() {
    std::cout << "Dog default constructor called\n";
    type_ = "Dog";
}

Dog::Dog(const Dog& src) {
    std::cout << "Dog copy constructor called\n";
    type_ = src.type_;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() { std::cout << "Dog default destructor called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog& Dog::operator=(Dog const& rhs) {
    if ( this != &rhs ) {
        type_ = rhs.type_;
    }
    return *this;
}

// std::ostream& operator<<(std::ostream& o, Dog const& i) {
//     // o << "Value = " << i.getValue();
//     return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() const { std::cout << "woof\n"; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Dog::getType() const { return type_; }

/* ************************************************************************ */