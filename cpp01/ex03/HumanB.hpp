/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 04:55:18 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/04 18:32:40 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB {
   public:
    void attack();
    void setWeapon(Weapon& weapon);
    Weapon* getWeapon();

    HumanB();
    HumanB(HumanB const& src);
    HumanB(std::string name);
    ~HumanB();

    HumanB& operator=(HumanB const& rhs);

   private:
    std::string name;
    Weapon* weapon;
};

#endif /* ******************************************************** HUMANB_H */