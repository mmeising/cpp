/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:15:16 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/06 18:52:00 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

bool Bureaucrat::messages_ = false;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() {
    if (messages_) {
        std::cout << "Bureaucrat default constructor called\n";
    }
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : name_(name), grade_(grade) {
    if (messages_) {
        std::cout << "Bureaucrat named + graded constructor called\n";
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) {
    if (messages_) {
        std::cout << "Bureaucrat copy constructor called\n";
    }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {
    if (messages_) {
        std::cout << "Bureaucrat default destructor called\n";
    }
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
    // if ( this != &rhs )
    //{
    // this->_value = rhs.getValue();
    //}
    return *this;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i) {
    // o << "Value = " << i.getValue();
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************ */