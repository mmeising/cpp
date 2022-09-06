/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:30:57 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/06 15:13:43 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() {
    std::cout << "Dog default constructor called\n";
    type_ = "Dog";
    brain_ = new Brain();
}

Dog::Dog(const Dog& src) {
    std::cout << "Dog copy constructor called\n";
    type_ = src.type_;
    brain_ = new Brain(*src.brain_);
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog() {
    std::cout << "Dog default destructor called\n";
    delete brain_;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog& Dog::operator=(Dog const& rhs) {
    if (this != &rhs) {
        type_ = rhs.type_;
        brain_ = rhs.brain_;
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
Brain* Dog::getBrain() { return brain_; }

/* ************************************************************************ */