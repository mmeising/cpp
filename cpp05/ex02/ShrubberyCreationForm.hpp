/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:32:12 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/20 21:30:52 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <iostream>
#include <string>

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
   public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const& src);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const& executor) const;

    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

   private:
};

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const& i);

#endif /* ***************************************** SHRUBBERYCREATIONFORM_H */