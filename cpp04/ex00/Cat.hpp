/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:34:48 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/30 18:35:18 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"

class Cat : public Animal {
   public:
    Cat();
    Cat(Cat const& src);
    ~Cat();

    void makeSound() const;

    std::string getType() const;

    Cat& operator=(Cat const& rhs);

   private:
};

// std::ostream& operator<<(std::ostream& o, Cat const& i);

#endif /* *********************************************************** CAT_H */