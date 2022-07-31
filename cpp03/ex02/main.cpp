/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 09:07:12 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/31 15:48:09 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ScavTrap scav_def;
    ScavTrap scav("scav");
    ScavTrap scav_copy(scav);
    std::cout << "\n";

    ClapTrap clap("clap");
    std::cout << "\n";

    FragTrap frag_def;
    FragTrap frag("frag");
    FragTrap frag_copy(frag);
    std::cout << "\n";

    scav.guardGate();
    clap.attack("scav");
    scav.takeDamage(0);
    scav.attack("clap");
    clap.takeDamage(20);
    std::cout << "\n";

    frag.attack("scav");
    scav.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();
    std::cout << "\n";

    return 0;
}
