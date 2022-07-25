/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 09:07:12 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/25 15:43:31 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("clap");
    ClapTrap trap("trap");
    ClapTrap def;

    clap.attack("trap");
    trap.takeDamage(0);
    for (int i = 0; i < 9; i++) {
        clap.beRepaired(1);
    }
    // clap no energy points left
    clap.attack("trap");
    clap.beRepaired(1);

    def.attack("clap");
    clap.takeDamage(0);
}
