/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 09:07:12 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/25 17:35:23 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap def;
    ScavTrap one("one");
    ScavTrap copy(one);
    ClapTrap clap("clap");

    one.guardGate();
    clap.attack("one");
    one.takeDamage(0);
    one.attack("clap");
    clap.takeDamage(20);
}
