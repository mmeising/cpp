/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:47:32 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/04 18:29:00 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
   public:
    const std::string& getType() const;
    void setType(std::string const& new_type);

    Weapon();
    Weapon(Weapon const& src);
    Weapon(std::string type);
    ~Weapon();

    Weapon& operator=(Weapon const& rhs);

   private:
    std::string type;
};

std::ostream& operator<<(std::ostream& o, Weapon const& i);

#endif /* ******************************************************** WEAPON_H */