/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:15:27 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/21 20:01:07 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat Alex = Bureaucrat("Alex", 146);
    Bureaucrat Bernd = Bureaucrat("Bernd", 46);
    Bureaucrat Charlie = Bureaucrat("Charlie", 5);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("C3PO");
    PresidentialPardonForm pardon("Your soul");

    Alex.signForm(shrub);
    Alex.incrementGrade();
    Alex.signForm(shrub);
    Bernd.executeForm(shrub);
    Bernd.signForm(robo);
    Bernd.incrementGrade();
    Bernd.executeForm(robo);
    Bernd.executeForm(robo);
    Bernd.executeForm(robo);
    Bernd.executeForm(robo);
    Charlie.signForm(pardon);
    Charlie.executeForm(pardon);
    return 0;
}
