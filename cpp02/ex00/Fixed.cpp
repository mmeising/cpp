/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:16:42 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/08 18:40:19 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : val_(0) { std::cout << "Default constructor called\n"; }

Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called\n";
    val_ = src.getRawBits();//either this line or
    // *this = src;         //this copy assignment operator call
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed& Fixed::operator=(Fixed const& rhs) {
    if (this != &rhs) {
        std::cout << "Copy assignment operator called\n";
        val_ = rhs.getRawBits();
    }
    return *this;
}

// std::ostream& operator<<(std::ostream& o, Fixed const& i) {
//     // o << "Value = " << i.getValue();
//     return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return val_;
}

void Fixed::setRawBits(int const raw) {
    val_ = raw;
}

/* ************************************************************************ */