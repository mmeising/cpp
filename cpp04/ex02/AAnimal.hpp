/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.hpp                                        :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:19:09 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/06 16:47:59 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
   protected:
    std::string type_;

   public:
    AAnimal();
    AAnimal(AAnimal const& src);
    virtual ~AAnimal();

    virtual void makeSound() const = 0;

    std::string getType() const;

    AAnimal& operator=(AAnimal const& rhs);

   private:
};

// std::ostream& operator<<(std::ostream& o, AAnimal const& i);

#endif /* ******************************************************* AANIMAL_H */