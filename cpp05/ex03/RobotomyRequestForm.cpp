/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:26:36 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/21 19:55:17 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm()
    : Form::Form("default", 72, 45, "default") {
    if (messages_) {
        std::cout << "RobotomyRequestForm default constructor called\n";
    }
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form::Form("Robotomy", 72, 45, target) {
    if (messages_) {
        std::cout << "RobotomyRequestForm constructor called\n";
    }
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) {
    if (messages_) {
        std::cout << "RobotomyRequestForm copy constructor called\n";
    }
    if (this != &src) {
        setSigned(src.getSigned());
    }
    std::cout << "As every variable but the signed status is const, only that "
                 "can be changed\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() {
    if (messages_) {
        std::cout << "RobotomyRequestForm destructor called\n";
    }
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm& RobotomyRequestForm::operator=(
    RobotomyRequestForm const& rhs) {
    if (this != &rhs) {
        setSigned(rhs.getSigned());
    }
    std::cout << "As every variable but the signed status is const, only that "
                 "can be changed\n";
    if (RobotomyRequestForm::messages_) {
        std::cout << "RobotomyRequestForm assignment operator called\n";
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, RobotomyRequestForm const& i) {
    o << "RobotomyRequestForm, target " << i.getTarget();
    if (i.getSigned()) {
        o << ", signed";
    } else {
        o << ", not signed";
    }
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    static bool random = false;

    if (getSigned() && executor.getGrade() <= 45) {
        std::cout << "BRRRT... BRR... BWWZZZZZ (drilling noises)\n";
        if (random) {
            std::cout << getTarget() << " has been robotomized\n";
            random = false;
        } else {
            std::cout << "Robotomy of " << getTarget() << " failed\n";
            random = true;
        }
    } else {
        throw Form::NotExecutableException();
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************ */