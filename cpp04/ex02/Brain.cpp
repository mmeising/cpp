/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:22:08 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/06 13:10:37 by mmeising         ###   ########.fr       */
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
    for (int i = 0; i < 100; i++) {
        ideas_[i] = src.ideas_[i];
    }
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

Brain& Brain::operator=(Brain const& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < 100; i++) {
            ideas_[i] = rhs.ideas_[i];
        }
    }
    return *this;
}

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

std::string* Brain::getIdeas() { return ideas_; }

std::string Brain::getIdea(int i) {
    if (i >= 0 && i <= 99) {
        return ideas_[i];
    }
    return NULL;
}

void Brain::setIdea(int i, std::string idea) {
    if (i >= 0 && i <= 99) {
        ideas_[i] = idea;
    }
}

/* ************************************************************************ */