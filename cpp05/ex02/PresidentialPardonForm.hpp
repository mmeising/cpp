/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:24:26 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/21 19:50:10 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>

#include "Form.hpp"

class PresidentialPardonForm : public Form {
   public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const& src);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);

    void execute(Bureaucrat const& executor) const;

   private:
};

std::ostream& operator<<(std::ostream& o, PresidentialPardonForm const& i);

#endif /* **************************************** PRESIDENTIALPARDONFORM_H */