/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:05:03 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/03 00:28:34 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string string = "HI THIS IS BRAIN";

    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "Address of string:    " << &string << "\n"
              << "Address in stringPTR: " << stringPTR << "\n"
              << "Address in stringREF: " << &stringREF << "\n"
              << "\n"
              << "value of string:               " << string << "\n"
              << "value pointed to by stringPTR: " << *stringPTR << "\n"
              << "value pointed to by stringREF: " << stringREF << "\n";
    return 0;
}
