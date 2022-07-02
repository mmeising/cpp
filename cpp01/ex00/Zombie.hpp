/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:56:28 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/02 22:37:42 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie {
   public:
    void announce(void);

    Zombie();
    Zombie(std::string name);
    Zombie(Zombie const& src);
    ~Zombie();

    Zombie& operator=(Zombie const& rhs);

   private:
    std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif /* ******************************************************** ZOMBIE_H */