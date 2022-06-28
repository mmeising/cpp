/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:26:47 by mmeising          #+#    #+#             */
/*   Updated: 2022/06/28 17:40:26 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PhoneBook::PhoneBook()
{
}

PhoneBook::PhoneBook( const PhoneBook & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PhoneBook::~PhoneBook()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PhoneBook &				PhoneBook::operator=( PhoneBook const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PhoneBook const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */