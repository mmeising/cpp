/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:24:33 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/21 19:50:30 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm()
    : Form::Form("default", 25, 5, "default") {
    if (messages_) {
        std::cout << "PresidentialPardonForm default constructor called\n";
    }
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : Form::Form("Pardon", 25, 5, target) {
    if (messages_) {
        std::cout << "PresidentialPardonForm constructor called\n";
    }
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& src) {
    if (messages_) {
        std::cout << "PresidentialPardonForm copy constructor called\n";
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

PresidentialPardonForm::~PresidentialPardonForm() {
    if (messages_) {
        std::cout << "PresidentialPardonForm destructor called\n";
    }
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm& PresidentialPardonForm::operator=(
    PresidentialPardonForm const& rhs) {
    if (this != &rhs) {
        setSigned(rhs.getSigned());
    }
    std::cout << "As every variable but the signed status is const, only that "
                 "can be changed\n";
    if (PresidentialPardonForm::messages_) {
        std::cout << "PresidentialPardonForm assignment operator called\n";
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, PresidentialPardonForm const& i) {
    o << "PresidentialPardonForm, target " << i.getTarget();
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

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (getSigned() && executor.getGrade() <= 5) {
        std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
    } else {
        throw Form::NotExecutableException();
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************ */