/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:19:09 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/01 16:51:44 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
   protected:
    std::string type_;

   public:
    Animal();
    Animal(Animal const& src);
    ~Animal();

    virtual void makeSound() const;

    std::string getType() const;

    Animal& operator=(Animal const& rhs);

   private:
};

// std::ostream& operator<<(std::ostream& o, Animal const& i);

#endif /* ******************************************************** ANIMAL_H */