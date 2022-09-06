/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:30:33 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/06 13:42:03 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() {
    std::cout << "Cat default constructor called\n";
    type_ = "Cat";
    brain_ = new Brain();
}

Cat::Cat(const Cat& src) {
    std::cout << "Cat copy constructor called\n";
    type_ = src.type_;
    brain_ = new Brain(*src.brain_);

}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat() {
    std::cout << "Cat default destructor called\n";
    delete brain_;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat& Cat::operator=(Cat const& rhs) {
    if (this != &rhs) {
        type_ = rhs.type_;
        brain_ = rhs.brain_;
    }
    return *this;
}

// std::ostream& operator<<(std::ostream& o, Cat const& i) {
//     // o << "Value = " << i.getValue();
//     return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const { std::cout << "meow\n"; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Cat::getType() const { return type_; }

Brain* Cat::getBrain() { return brain_; }

/* ************************************************************************ */