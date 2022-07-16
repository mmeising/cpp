/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:56:41 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/16 09:16:57 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
   public:
    ClapTrap();
    ClapTrap(ClapTrap const& src);
    ClapTrap(std::string name);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    ClapTrap& operator=(ClapTrap const& rhs);

   private:
    std::string name_;
    int hit_points_;
    int energy_points_;
    int attack_dmg_;
};

std::ostream& operator<<(std::ostream& o, ClapTrap const& i);

#endif /* ****************************************************** CLAPTRAP_H */