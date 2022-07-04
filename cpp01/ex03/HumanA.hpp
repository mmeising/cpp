/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 04:04:51 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/04 18:31:42 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanA {
   public:
    void attack();

    HumanA(HumanA const& src);
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();

    HumanA& operator=(HumanA const& rhs);

   private:
    std::string name;
    Weapon& weapon;
};

#endif /* ******************************************************** HUMANA_H */