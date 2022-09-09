/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:50:43 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/09 22:13:14 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Form {
   public:
    Form();
    Form(std::string name, int req_sign, int req_exec);
    Form(Form const& src);
    ~Form();

    void signForm();

    std::string const getName() const;
    bool getSigned() const;
    int const getReqSign() const;
    int const getReqExec() const;

    Form& operator=(Form const& rhs);

   private:
    std::string const name_;
    bool signed_;
    int const req_sign_;
    int const req_exec_;
};

std::ostream& operator<<(std::ostream& o, Form const& i);

#endif /* ********************************************************** FORM_H */