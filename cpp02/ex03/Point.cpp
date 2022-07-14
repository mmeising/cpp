/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:45:09 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/15 00:39:04 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool Point::messages_ = false;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : x_(0), y_(0) {
    if (messages_) {
        std::cout << "Point default constructor called\n";
    }
}

Point::Point(const Point& src) : x_(src.x_), y_(src.y_) {
    if (messages_) {
        std::cout << "Point copy constructor called\n";
    }
}

Point::Point(const float x, const float y) : x_(x), y_(y) {
    if (messages_) {
        std::cout << "Point floats constructor called\n";
    }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point() {
    if (messages_) {
        std::cout << "Point destructor called\n";
    }
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point& Point::operator=(Point const& rhs) {
    (void)rhs;
    if (messages_) {
        std::cout << "Point copy assignment operator overload called\n";
    }
    throw std::runtime_error("can't reassign const values");
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const Fixed& Point::getX() const { return x_; }
const Fixed& Point::getY() const { return y_; }

/* ************************************************************************ */