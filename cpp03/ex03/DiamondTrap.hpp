/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:47:37 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/31 17:00:11 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap {
   public:
    DiamondTrap();
    DiamondTrap(DiamondTrap const& src);
    DiamondTrap(std::string name);
    ~DiamondTrap();

    void attack(const std::string& target);
    void whoAmI();

    DiamondTrap& operator=(DiamondTrap const& rhs);

   private:
};

#endif /* ****************************************************** FragTrap_H */