/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:50:43 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/20 20:18:11 by mmeising         ###   ########.fr       */
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
    class NotExecutableException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
    Form();
    Form(std::string name, int req_sign, int req_exec, std::string target);
    Form(Form const& src);
    ~Form();

    void setSigned(bool sign);

    std::string const getName() const;
    bool getSigned() const;
    int getReqSign() const;
    int getReqExec() const;
    std::string getTarget() const;

    void beSigned(Bureaucrat& signee);
    virtual void execute(Bureaucrat const& executor) const = 0;

    Form& operator=(Form const& rhs);

    static bool messages_;

   private:
    std::string const name_;
    bool signed_;
    int const req_sign_;
    int const req_exec_;
    std::string const target_;
};

std::ostream& operator<<(std::ostream& o, Form const& i);

#endif /* ********************************************************** FORM_H */