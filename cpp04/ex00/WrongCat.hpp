/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:34:48 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/10 17:46:14 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <iostream>
#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
   public:
    WrongCat();
    WrongCat(WrongCat const& src);
    ~WrongCat();

    void makeSound() const;

    std::string getType() const;

    WrongCat& operator=(WrongCat const& rhs);

   private:
};

// std::ostream& operator<<(std::ostream& o, Cat const& i);

#endif /* *********************************************************** CAT_H */