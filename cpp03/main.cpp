/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 09:07:12 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/16 09:20:04 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("clap");
    ClapTrap trap("trap");
    ClapTrap def;

    clap.attack("trap");
    clap.beRepaired(1);
}
