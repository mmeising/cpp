/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:33:38 by mmeising          #+#    #+#             */
/*   Updated: 2022/06/30 02:20:31 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
using std::string;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Contact::Contact() {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Contact::~Contact() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
**                                   GETTERS
*/

const string &Contact::get_firstname() const { return (first_name_); }
const string &Contact::get_lastname() const { return (last_name_); }
const string &Contact::get_nickname() const { return (nickname_); }
const string &Contact::get_phone_number() const { return (phone_number_); }
const string &Contact::get_secret() const { return (secret_); }

/*
**                                   SETTERS
*/

void Contact::set_firstname(string content) { first_name_ = content; }
void Contact::set_lastname(string content) { last_name_ = content; }
void Contact::set_nickname(string content) { nickname_ = content; }
void Contact::set_phone_number(string content) { phone_number_ = content; }
void Contact::set_secret(string content) { secret_ = content; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */