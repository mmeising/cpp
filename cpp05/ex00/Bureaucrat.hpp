/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:15:01 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/06 18:50:27 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
   public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const& src);
    ~Bureaucrat();

    Bureaucrat& operator=(Bureaucrat const& rhs);

   private:
    std::string name_;
    int grade_;
    static bool messages_;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i);

#endif /* **************************************************** BUREAUCRAT_H */