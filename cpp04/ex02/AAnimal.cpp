/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:18:57 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/01 16:32:21 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal() { std::cout << "AAnimal default constructor called\n"; }

AAnimal::AAnimal(const AAnimal& src) {
    std::cout << "AAnimal copy constructor called\n";
    type_ = src.type_;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal() { std::cout << "AAnimal default destructor called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal& AAnimal::operator=(AAnimal const& rhs) {
    if (this != &rhs) {
        type_ = rhs.type_;
    }
    return *this;
}

// std::ostream& operator<<(std::ostream& o, AAnimal const& i) {
//     // o << "Value = " << i.getValue();
//     return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

// void AAnimal::makeSound() const {
//     std::cout << "I'm not a real Aanimal, I don't make a sound\n";
// }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AAnimal::getType() const { return type_; }

/* ************************************************************************ */