/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:34:39 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/10 17:46:42 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_DOG_HPP
#define WRONG_DOG_HPP

#include <iostream>
#include <string>

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
   public:
    WrongDog();
    WrongDog(WrongDog const& src);
    ~WrongDog();

    void makeSound() const;
    std::string getType() const;

    WrongDog& operator=(WrongDog const& rhs);

   private:
};

// std::ostream& operator<<(std::ostream& o, Dog const& i);

#endif /* *********************************************************** DOG_H */