/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:22:08 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/31 15:31:49 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() {
    std::cout << "Brain default constructor called\n";
    // stuff
}

Brain::Brain(const Brain& src) {
    std::cout << "Brain copy constructor called\n";
    // stuff
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain() {
    std::cout << "Brain default destructor called\n";
    // stuff
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Brain& Brain::operator=(Brain const& rhs) {
//     // if ( this != &rhs )
//     //{
//     // this->_value = rhs.getValue();
//     //}
//     return *this;
// }

// std::ostream &			operator<<( std::ostream & o, Brain
// const
// &
// i
// )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************ */