/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:33:42 by mmeising          #+#    #+#             */
/*   Updated: 2022/06/30 02:20:04 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
   public:

    Contact();
    ~Contact();

    const std::string &get_firstname() const;
    const std::string &get_lastname() const;
    const std::string &get_nickname() const;
    const std::string &get_phone_number() const;
    const std::string &get_secret() const;

    void set_firstname(std::string content);
    void set_lastname(std::string content);
    void set_nickname(std::string content);
    void set_phone_number(std::string content);
    void set_secret(std::string content);

   private:
    std::string first_name_;
    std::string last_name_;
    std::string nickname_;
    std::string phone_number_;
    std::string secret_;
};

#endif /* ******************************************************* CONTACT_H */
