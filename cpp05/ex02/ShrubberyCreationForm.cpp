/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:32:23 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/20 21:38:07 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form::Form("default", 145, 137, "default") {
    if (messages_) {
        std::cout << "ShrubberyCreationForm default constructor called\n";
    }
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form::Form("Shrubbery", 145, 137, target) {
    if (messages_) {
        std::cout << "ShrubberyCreationForm constructor called\n";
    }
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) {
    if (messages_) {
        std::cout << "ShrubberyCreationForm copy constructor called\n";
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

ShrubberyCreationForm::~ShrubberyCreationForm() {
    if (messages_) {
        std::cout << "ShrubberyCreationForm destructor called\n";
    }
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const& rhs) {
    if (this != &rhs) {
        setSigned(rhs.getSigned());
    }
    std::cout << "As every variable but the signed status is const, only that "
                 "can be changed\n";
    if (ShrubberyCreationForm::messages_) {
        std::cout << "Form assignment operator called\n";
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const& i) {
    o << "ShrubberyCreationForm, target " << i.getTarget();
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

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (getSigned() && executor.getGrade() <= 137) {
        std::ofstream file(getTarget() + "_shrubbery");
        file << "       _-_\n"
                "    /~~   ~~\\\n"
                " /~~         ~~\\\n"
                "{               }\n"
                " \\  _-     -_  /\n"
                "   ~  \\\\ //  ~\n"
                "_- -   | | _- _\n"
                "  _ -  | |   -_\n"
                "      // \\\\\n";
        file.close();
    } else {
        throw Form::NotExecutableException();
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************ */