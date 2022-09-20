/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:50:43 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/16 15:30:41 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
   public:
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
    class AlreadySignedException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
    Form();
    Form(std::string name, int req_sign, int req_exec);
    Form(Form const& src);
    ~Form();

    std::string const getName() const;
    bool getSigned() const;
    int getReqSign() const;
    int getReqExec() const;

    void beSigned(Bureaucrat& signee);

    Form& operator=(Form const& rhs);

   private:
    std::string const name_;
    bool signed_;
    int const req_sign_;
    int const req_exec_;
    static bool messages_;
};

std::ostream& operator<<(std::ostream& o, Form const& i);

#endif /* ********************************************************** FORM_H */