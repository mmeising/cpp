/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:33:38 by mmeising          #+#    #+#             */
/*   Updated: 2022/06/30 22:44:09 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
using std::string;

Contact::Contact() { std::cout << "Contact Constructor called\n"; }
Contact::~Contact() { std::cout << "Contact Destructor called\n"; }

/*
** --------------------------------- GETTERS ----------------------------------
*/

const string &Contact::get_firstname() const { return (first_name_); }
const string &Contact::get_lastname() const { return (last_name_); }
const string &Contact::get_nickname() const { return (nickname_); }
const string &Contact::get_phone_number() const { return (phone_num_); }
const string &Contact::get_secret() const { return (secret_); }

/*
** --------------------------------- SETTERS ----------------------------------
*/

void Contact::set_firstname(const string content) { first_name_ = content; }
void Contact::set_lastname(const string content) { last_name_ = content; }
void Contact::set_nickname(const string content) { nickname_ = content; }
void Contact::set_phone_number(const string content) { phone_num_ = content; }
void Contact::set_secret(const string content) { secret_ = content; }
