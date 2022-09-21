/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:15:16 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/21 20:00:50 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

bool Bureaucrat::messages_ = true;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : name_("default"), grade_(150) {
    if (Bureaucrat::messages_) {
        std::cout << "Bureaucrat default constructor called\n";
    }
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    } else {
        grade_ = grade;
    }
    if (Bureaucrat::messages_) {
        std::cout << "Bureaucrat constructor called\n";
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : name_(src.name_), grade_(src.grade_) {
    if (Bureaucrat::messages_) {
        std::cout << "Bureaucrat copy constructor called\n";
    }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {
    if (Bureaucrat::messages_) {
        std::cout << "Bureaucrat default destructor called\n";
    }
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
    if (this != &rhs) {
        grade_ = rhs.getGrade();
    }
    if (Bureaucrat::messages_) {
        std::cout << "Bureaucrat assignment operator called\n";
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i) {
    o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".\n";
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::incrementGrade() {
    if (grade_ <= 1) {
        throw Bureaucrat::GradeTooHighException();
    } else {
        grade_--;
    }
}

void Bureaucrat::decrementGrade() {
    if (grade_ >= 150) {
        throw Bureaucrat::GradeTooLowException();
    } else {
        grade_++;
    }
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << "\n";
    } catch (Form::GradeTooLowException& e) {
        std::cout << this->getName() << " couldn't sign " << form.getName()
                  << " because their grade is too low\n";
    }
}

void Bureaucrat::executeForm(Form const& form) {
    try {
        form.execute(*this);
        std::cout << name_ << " executed " << form.getName() << "\n";
    } catch (Form::NotExecutableException& e) {
        std::cout << e.what();
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName() const { return name_; }
int Bureaucrat::getGrade() const { return grade_; }

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "GradeTooHighException: Grade was set to higher than 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "GradeTooLowException: Grade was set to lower than 150.";
}

/* ************************************************************************ */