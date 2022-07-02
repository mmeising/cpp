/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 23:23:18 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/03 00:03:29 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int n = 3;
    Zombie* horde = zombieHorde(n, "yay");

    for (int i = 0; i < n; i++) {
        horde[i].announce();
    }
    // Zombie special(horde[0]);
    // std::cout << "special:\n";
    // special.announce();
    delete[] horde;
    return 0;
}
