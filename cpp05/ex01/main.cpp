/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:15:27 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/13 17:36:25 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat Alex = Bureaucrat("Alex", 100);
    Bureaucrat Bernie = Bureaucrat();
    Bureaucrat Charlie = Bureaucrat(Alex);
    Bureaucrat Doris;
    std::cout << "\n";
    try {
        Doris = Bureaucrat("Doris", 170);
        std::cout << "Doris' name is " << Doris.getName();
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        //catching only this specific Exception
        std::cout << "catch block from GradeTooHighException\n";
    }
    catch (std::exception& e) {
        //catching any other exception that is like std::exception
        std::cout << "catch block from std::exception\n";
    }
    std::cout << "\n";
    std::cout << Alex;
    std::cout << Bernie;
    std::cout << Charlie;
    std::cout << Doris;
    std::cout << "\n";
    try {
        Alex.incrementGrade();
        Bernie.decrementGrade();
    }
    catch (std::exception& e) {
        std::cout << "catch block after increment/decrement\n";
    }
    std::cout << "\n";
    std::cout << Alex;
    std::cout << Bernie;
    std::cout << "\n";
    std::cout << "\nTesting forms next:\n";
    try {
        Form form_default = Form();
        Form form_named = Form("some_bureaucrocy_stuff.A", 100, 80);
        Form form_copy = Form(form_named);
        std::cout << form_default << std::endl;
        std::cout << form_named << std::endl;
        Alex.signForm(form_named);
        Alex.decrementGrade();
        Alex.decrementGrade();
        Alex.signForm(form_copy);
        Form form_error = Form("error", 170, 1);
    }
    catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }
    return 0;
}
