/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:34:48 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/30 16:53:15 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <iostream>
#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
   public:
    WrongCat(void);
    WrongCat(WrongCat const& src);
    ~WrongCat(void);

    void makeSound(void) const;

    std::string getType(void) const;

    WrongCat& operator=(WrongCat const& rhs);

   private:
};

// std::ostream& operator<<(std::ostream& o, Cat const& i);

#endif /* *********************************************************** CAT_H */