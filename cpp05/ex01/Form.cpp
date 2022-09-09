/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:51:00 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/09 22:13:36 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : name_("default"), req_sign_(150), req_exec_(150) {}

Form::Form(std::string name, int req_sign, int req_exec)
    : name_(name), req_sign_(req_sign), req_exec_(req_exec) {}

Form::Form(const Form& src)
    : name_(src.name_), req_sign_(src.req_sign_), req_exec_(src.req_exec_) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Form& Form::operator=(Form const& rhs) {
//     // if ( this != &rhs )
//     //{
//     // this->_value = rhs.getValue();
//     //}
//     return *this;
// }

std::ostream& operator<<(std::ostream& o, Form const& i) {
    o << i.getName() << " requires grade " << i.getReqExec()
      << " to be executed and grade " << i.getReqSign() << " to be signed\n";
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************ */