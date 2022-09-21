/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:26:55 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/21 19:53:49 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>

#include "Form.hpp"

class RobotomyRequestForm : public Form {
   public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const& src);
    ~RobotomyRequestForm();

    RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);

    void execute(Bureaucrat const& executor) const;

   private:
};

std::ostream& operator<<(std::ostream& o, RobotomyRequestForm const& i);

#endif /* ******************************************* ROBOTOMYREQUESTFORM_H */