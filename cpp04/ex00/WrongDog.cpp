/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:30:57 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/10 15:38:42 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongDog::WrongDog() {
    std::cout << "WrongDog default constructor called\n";
    type_ = "WrongDog";
}

WrongDog::WrongDog(const WrongDog& src) {
    std::cout << "WrongDog copy constructor called\n";
    type_ = src.type_;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongDog::~WrongDog() { std::cout << "WrongDog default destructor called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongDog& WrongDog::operator=(WrongDog const& rhs) {
    if ( this != &rhs ) {
        type_ = rhs.type_;
    }
    return *this;
}

// std::ostream& operator<<(std::ostream& o, WrongDog const& i) {
//     // o << "Value = " << i.getValue();
//     return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongDog::makeSound() const { std::cout << "woof\n"; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongDog::getType() const { return type_; }

/* ************************************************************************ */