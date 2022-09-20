/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:51:00 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/20 21:17:07 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

bool Form::messages_ = true;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form()
    : name_("default"),
      signed_(false),
      req_sign_(150),
      req_exec_(150),
      target_("default") {
    if (Form::messages_) {
        std::cout << "Form default constructor called\n";
    }
}

Form::Form(std::string name, int req_sign, int req_exec, std::string target)
    : name_(name),
      signed_(false),
      req_sign_(req_sign),
      req_exec_(req_exec),
      target_(target) {
    if (req_sign_ < 1 || req_exec_ < 1) {
        throw(Form::GradeTooHighException());
    } else if (req_sign_ > 150 || req_exec_ > 150) {
        throw(Form::GradeTooLowException());
    }
    if (Form::messages_) {
        std::cout << "Form constructor with values called\n";
    }
}

Form::Form(const Form& src)
    : name_(src.name_),
      signed_(src.signed_),
      req_sign_(src.req_sign_),
      req_exec_(src.req_exec_),
      target_(src.target_) {
    if (Form::messages_) {
        std::cout << "Form copy constructor called\n";
    }
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {
    if (Form::messages_) {
        std::cout << "Form default destructor called\n";
    }
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form& Form::operator=(Form const& rhs) {
    if (this != &rhs) {
        setSigned(rhs.getSigned());
    }
    std::cout << "As every variable but the signed status is const, only that "
                 "can be changed\n";
    if (Form::messages_) {
        std::cout << "Form assignment operator called\n";
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, Form const& i) {
    o << i.getName() << " requires grade " << i.getReqExec()
      << " to be executed and grade " << i.getReqSign()
      << " to be signed. It is ";
    if (i.getSigned() == true) {
        o << "already signed";
    } else {
        o << "not signed";
    }
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat& signee) {
    if (signee.getGrade() <= getReqSign()) {
        signed_ = true;
    } else {
        throw(Form::GradeTooLowException());
    }
}
/*
** --------------------------------- MUTATOR ----------------------------------
*/

void Form::setSigned(bool sign) {
    signed_ = sign;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const Form::getName() const { return name_; }
bool Form::getSigned() const { return signed_; }
int Form::getReqSign() const { return req_sign_; }
int Form::getReqExec() const { return req_exec_; }
std::string Form::getTarget() const { return target_; }

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

const char* Form::GradeTooHighException::what() const throw() {
    return "GradeTooHighException: Grade was set to higher than 1.";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "GradeTooLowException: Grade was set to lower than 150.";
}

const char* Form::NotExecutableException::what() const throw() {
    return "NotExecutableException: Form couldn't be executed, either because "
           "the grade of the bureaucrat is too low or because the form wasn't "
           "signed.";
}

/* ************************************************************************ */