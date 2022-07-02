/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:31:14 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/02 22:50:18 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie zombie_stack("stack");
    Zombie* zombie_heap;

    std::cout << "beginning of main code\n";
    zombie_heap = newZombie("heap");
    randomChump("random");
    zombie_stack.announce();
    delete zombie_heap;
    return 0;
}
