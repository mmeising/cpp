/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:19:09 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/30 20:39:35 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
   protected:
    std::string type_;

   public:
    WrongAnimal();
    WrongAnimal(WrongAnimal const& src);
    virtual ~WrongAnimal();

    void makeSound() const;

    std::string getType() const;

    WrongAnimal& operator=(WrongAnimal const& rhs);

   private:
};

// std::ostream& operator<<(std::ostream& o, Animal const& i);

#endif /* ******************************************************** ANIMAL_H */