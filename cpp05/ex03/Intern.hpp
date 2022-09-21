/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:03:22 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/21 21:25:35 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "Form.hpp"

class Intern {
   public:
    class FormNotFoundException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
    Intern();
    Intern(Intern const& src);
    ~Intern();

    Intern& operator=(Intern const& rhs);

    Form* makeForm(std::string name, std::string target);

   private:
    enum forms {
        SHRUBBERY = 1,
        ROBOTOMY = 2,
        PRESIDENT = 3
    };
};

std::ostream& operator<<(std::ostream& o, Intern const& i);

#endif /* ******************************************************** INTERN_H */