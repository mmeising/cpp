/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:15:01 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/13 13:59:39 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
   public:
    class GradeTooHighException : public std::exception {
       public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        const char* what() const throw();
    };
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const& src);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    Bureaucrat& operator=(Bureaucrat const& rhs);

   private:
    std::string name_;
    int grade_;
    static bool messages_;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i);

#endif /* **************************************************** BUREAUCRAT_H */