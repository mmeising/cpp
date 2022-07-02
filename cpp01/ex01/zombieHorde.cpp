/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 23:22:16 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/02 23:33:11 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* zombie_horde = new Zombie[N];

    for (int i = 0; i < N; i++) {
        zombie_horde[i].setName(name);
    }
    return (zombie_horde);
}
