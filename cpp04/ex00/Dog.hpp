/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:34:39 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/01 15:39:15 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>

class Dog {
   public:
    Dog();
    Dog(Dog const& src);
    ~Dog();

    Dog& operator=(Dog const& rhs);

   private:
};

std::ostream& operator<<(std::ostream& o, Dog const& i);

#endif /* *********************************************************** DOG_H */