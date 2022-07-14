/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:32:22 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/14 23:33:26 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool Fixed::messages_ = false;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : val_(0) {
    if (messages_) {
        std::cout << "Fixed Default constructor called\n";
    }
}

Fixed::Fixed(const int input) {
    if (messages_) {
        std::cout << "Fixed Integer constructor called\n";
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
        std::cout << "Fixed Float constructor called\n";
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
        std::cout << "Fixed Copy constructor called\n";
    }
    val_ = src.getRawBits();  // either this line or ...
    // *this = src;         // ... this copy assignment operator call
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed() {
    if (messages_) {
        std::cout << "Fixed Destructor called\n";
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
            std::cout << "Fixed Copy assignment operator called\n";
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

bool Fixed::operator!=(Fixed& rhs) { return *this < rhs || rhs < *this; }

bool Fixed::operator==(Fixed& rhs) { return !(*this < rhs || rhs < *this); }

Fixed Fixed::operator+(Fixed const& rhs) const {
    Fixed result;

    result.setRawBits(this->getRawBits() + rhs.getRawBits());
    return result;
}

Fixed Fixed::operator-(Fixed const& rhs) const {
    Fixed result;

    result.setRawBits(this->getRawBits() - rhs.getRawBits());
    return result;
}

Fixed Fixed::operator*(Fixed const& rhs) const {
    Fixed result;

    result = Fixed(this->toFloat() * rhs.toFloat());
    return result;
}

Fixed Fixed::operator/(Fixed const& rhs) const {
    Fixed result;

    result = Fixed(this->toFloat() / rhs.toFloat());
    return result;
}

// Prefix Increment
Fixed& Fixed::operator++() {
    int raw = this->getRawBits();

    raw++;
    this->setRawBits(raw);
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
    return temp;
}

// Prefix Decrement
Fixed& Fixed::operator--() {
    int raw = this->getRawBits();

    raw--;
    this->setRawBits(raw);
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
    return temp;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float Fixed::toFloat() const { return ((float)getRawBits() / 256); }
int Fixed::toInt() const { return getRawBits() >> fract_; }

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (messages_) {
        std::cout << "Fixed min called\n";
    }
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (messages_) {
        std::cout << "Fixed max called\n";
    }
    if (b <= a) {
        return a;
    } else {
        return b;
    }
}

Fixed& Fixed::min(Fixed const& a, Fixed const& b) {
    if (messages_) {
        std::cout << "Fixed min const called\n";
    }
    if (a.getRawBits() < b.getRawBits()) {
        return (Fixed&)a;
    } else {
        return (Fixed&)b;
    }
}

Fixed& Fixed::max(Fixed const& a, Fixed const& b) {
    if (messages_) {
        std::cout << "Fixed max const called\n";
    }
    if (a.getRawBits() < b.getRawBits()) {
        return (Fixed&)a;
    } else {
        return (Fixed&)b;
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Fixed::getRawBits() const {
    if (messages_) {
        std::cout << "Fixed getRawBits member function called\n";
    }
    return val_;
}

/*
** --------------------------------- MUTATOR ----------------------------------
*/

void Fixed::setRawBits(int const raw) {
    if (messages_) {
        std::cout << "Fixed setRawBits member function called\n";
    }
    val_ = raw;
}

/* ************************************************************************ */