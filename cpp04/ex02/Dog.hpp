/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:34:39 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/06 16:49:43 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
   public:
    Dog();
    Dog(Dog const& src);
    ~Dog();

    void makeSound() const;
    std::string getType() const;
    Brain* getBrain();

    Dog& operator=(Dog const& rhs);

   private:
    Brain* brain_;
};

// std::ostream& operator<<(std::ostream& o, Dog const& i);

#endif /* *********************************************************** DOG_H */