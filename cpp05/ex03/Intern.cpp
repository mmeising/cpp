/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:03:32 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/21 21:44:35 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern() {}
Intern::Intern(const Intern& src) { (void)src; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern& Intern::operator=(Intern const& rhs) { 
    (void)rhs;
    return *this; }

std::ostream& operator<<(std::ostream& o, Intern const& i) {
    o << "Interns don't have unique characteristics, nothing to see here";
    (void)i;
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Form* Intern::makeForm(std::string name, std::string target) {
    int form_id = 0;

    std::string forms[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    for (int i = 0; i < 3; i++) {
        if (name == forms[i]) form_id = i + 1;
    }
    switch (form_id) {
        case SHRUBBERY:
            std::cout << "Intern creates " << name << " form\n";
            return new ShrubberyCreationForm(target);
        case ROBOTOMY:
            std::cout << "Intern creates " << name << " form\n";
            return new RobotomyRequestForm(target);
        case PRESIDENT:
            std::cout << "Intern creates " << name << " form\n";
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Intern might lose his job, he can't find the " << name << " form\n";
            throw FormNotFoundException();
    }
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "FormNotFoundException: Form not found.";
}

/* ************************************************************************ */