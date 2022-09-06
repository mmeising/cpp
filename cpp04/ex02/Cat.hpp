/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:34:48 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/06 16:49:15 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
   public:
    Cat();
    Cat(Cat const& src);
    ~Cat();

    void makeSound() const;

    std::string getType() const;
    Brain* getBrain();

    Cat& operator=(Cat const& rhs);

   private:
    Brain* brain_;
};

// std::ostream& operator<<(std::ostream& o, Cat const& i);

#endif /* *********************************************************** CAT_H */