/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:26:43 by mmeising          #+#    #+#             */
/*   Updated: 2022/06/30 03:08:39 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include <string>

#include "Contact.hpp"

class PhoneBook {
   public:
    PhoneBook();
    ~PhoneBook();

    void AddContact();
    void Search() const;

   private:
    Contact contacts[8];
    int i;

    Contact PromptUser();
};

#endif /* ****************************************************** PHONEBOOK_H*/