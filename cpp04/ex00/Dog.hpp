/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:34:39 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/30 18:35:21 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"

class Dog : public Animal {
   public:
    Dog();
    Dog(Dog const& src);
    ~Dog();

    void makeSound() const;
    std::string getType() const;

    Dog& operator=(Dog const& rhs);

   private:
};

// std::ostream& operator<<(std::ostream& o, Dog const& i);

#endif /* *********************************************************** DOG_H */