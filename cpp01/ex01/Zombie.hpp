/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 23:22:10 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/02 23:34:16 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie {
   public:
    void announce(void);
    void setName(std::string new_name);

    Zombie();
    Zombie(std::string name);
    Zombie(Zombie const& src);
    ~Zombie();

    Zombie& operator=(Zombie const& rhs);

   private:
    std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif /* ******************************************************** ZOMBIE_H */