/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:55:10 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/13 21:30:01 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool Fixed::messages_ = false;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : val_(0) {
    if (messages_) {
        std::cout << "Default constructor called\n";
    }
}

Fixed::Fixed(const int input) {
    if (messages_) {
        std::cout << "Integer constructor called\n";
    }
    if ((input > 0x7FFFFF) != 0) {
        std::cerr << "WARNING: input int ";
        std::cerr << input;
        std::cerr << " overflows Fixed type\n";
    }
    val_ = input << fract_;
}

Fixed::Fixed(const float input) {
    if (messages_) {
        std::cout << "Float constructor called\n";
    }
    if (input > 0x7FFFFF) {
        std::cerr << "WARNING: input float ";
        std::cerr << input;
        std::cerr << " overflows Fixed type\n";
    }
    setRawBits(roundf(input * 256));
}

Fixed::Fixed(const Fixed& src) {
    if (messages_) {
        std::cout << "Copy constructor called\n";
    }
    val_ = src.getRawBits();  // either this line or ...
    // *this = src;         // ... this copy assignment operator call
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {
    if (messages_) {
        std::cout << "Destructor called\n";
    }
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream& operator<<(std::ostream& o, Fixed const& i) {
    o << i.toFloat();
    return o;
}

Fixed& Fixed::operator=(Fixed const& rhs) {
    if (this != &rhs) {
        if (messages_) {
            std::cout << "Copy assignment operator called\n";
        }
        val_ = rhs.getRawBits();
    }
    return *this;
}

bool Fixed::operator<(Fixed& rhs) {
    return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>(Fixed& rhs) { return rhs < *this; }

bool Fixed::operator>=(Fixed& rhs) { return !(*this < rhs); }

bool Fixed::operator<=(Fixed& rhs) { return !(rhs < *this); }

bool Fixed::operator!=(Fixed& rhs) { return *this < rhs || rhs < *this;}

bool Fixed::operator==(Fixed& rhs) { 
    return !(*this < rhs || rhs < *this);
}

Fixed Fixed::operator+(Fixed const& rhs) {
    Fixed result;

    result.setRawBits(this->getRawBits() + rhs.getRawBits());
    return result;
}

Fixed Fixed::operator-(Fixed const& rhs) {
    Fixed result;

    result.setRawBits(this->getRawBits() - rhs.getRawBits());
    return result;
}

Fixed Fixed::operator*(Fixed const& rhs) {
    Fixed result;

    result = Fixed(this->toFloat() * rhs.toFloat());
    return result;
}

Fixed Fixed::operator/(Fixed const& rhs) {
    Fixed result;

    result = Fixed(this->toFloat() / rhs.toFloat());
    return result;
}

// Prefix Increment
Fixed& Fixed::operator++() {
    int raw = this->getRawBits();

    raw++;
    this->setRawBits(raw);
    // this->setRawBits(this->getRawBits()++);
    return *this;
}

// Postfix Increment
Fixed Fixed::operator++(int n) {
    Fixed temp;
    int raw = this->getRawBits();

    temp = *this;
    if (n == 0) {
        raw++;
    } else {
        raw += n;
    }
    this->setRawBits(raw);
    // this->setRawBits(this->getRawBits()++);
    return temp;
}

// Prefix Decrement
Fixed& Fixed::operator--() {
    int raw = this->getRawBits();

    raw--;
    this->setRawBits(raw);
    // this->setRawBits(this->getRawBits()--);
    return *this;
}

// Postfix Decrement
Fixed Fixed::operator--(int n) {
    Fixed temp;
    int raw = this->getRawBits();

    temp = *this;
    if (n == 0) {
        raw--;
    } else {
        raw -= n;
    }
    this->setRawBits(raw);
    // this->setRawBits(this->getRawBits()--);
    return temp;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float Fixed::toFloat() const { return ((float)getRawBits() / 256); }

int Fixed::toInt() const { return getRawBits() >> fract_; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits() const {
    if (messages_) {
        std::cout << "getRawBits member function called\n";
    }
    return val_;
}

/*
** --------------------------------- MUTATOR ----------------------------------
*/

void Fixed::setRawBits(int const raw) { val_ = raw; }

/* ************************************************************************ */