/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:11:30 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/06 20:02:21 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "DEBUG:\n";
    harl.complain("DEBUG");
    std::cout << "INFO:\n";
    harl.complain("INFO");
    std::cout << "WARNING:\n";
    harl.complain("WARNING");
    std::cout << "ERROR:\n";
    harl.complain("ERROR");
    std::cout << "INVALID STUFF:\n";
    harl.complain("INVALID STUFF");
    std::cout << "empty string:\n";
    harl.complain("");
    return 0;
}
