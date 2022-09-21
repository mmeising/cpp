/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:15:27 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/21 21:45:38 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    // Bureaucrat Alex = Bureaucrat("Alex", 146);
    // Bureaucrat Bernd = Bureaucrat("Bernd", 46);
    // Bureaucrat Charlie = Bureaucrat("Charlie", 5);

    // ShrubberyCreationForm shrub("home");
    // RobotomyRequestForm robo("C3PO");
    // PresidentialPardonForm pardon("Your soul");

    // Alex.signForm(shrub);
    // Alex.incrementGrade();
    // Alex.signForm(shrub);
    // Bernd.executeForm(shrub);
    // Bernd.signForm(robo);
    // Bernd.incrementGrade();
    // Bernd.executeForm(robo);
    // Bernd.executeForm(robo);
    // Bernd.executeForm(robo);
    // Bernd.executeForm(robo);
    // Charlie.signForm(pardon);
    // Charlie.executeForm(pardon);
    Bureaucrat Alex = Bureaucrat("Alex", 1);
    Intern unpaid;
    Form* form_0;

    std::cout << "\n";

    try {
        form_0 = unpaid.makeForm("robotomy request", "Bender");
        Alex.signForm(*form_0);
        Alex.executeForm(*form_0);
        delete form_0;

        std::cout << "\n";

        form_0 = unpaid.makeForm("shrubbery creation", "home");
        Alex.signForm(*form_0);
        Alex.executeForm(*form_0);
        delete form_0;

        std::cout << "\n";

        form_0 = unpaid.makeForm("presidential pardon", "your soul");
        Alex.signForm(*form_0);
        Alex.executeForm(*form_0);
        delete form_0;

        std::cout << "\n";

        form_0 = unpaid.makeForm("end of world hunger", "everyone");
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
