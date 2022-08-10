/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:30:33 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/01 16:32:25 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat() {
    std::cout << "WrongCat default constructor called\n";
    type_ = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src) {
    std::cout << "WrongCat copy constructor called\n";
    type_ = src.type_;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat() { std::cout << "WrongCat default destructor called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat& WrongCat::operator=(WrongCat const& rhs) {
    if ( this != &rhs ) {
        type_ = rhs.type_;
    }
    return *this;
}

// std::ostream& operator<<(std::ostream& o, WrongCat const& i) {
//     // o << "Value = " << i.getValue();
//     return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound() const { std::cout << "meow\n"; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string WrongCat::getType() const { return type_; }

/* ************************************************************************ */