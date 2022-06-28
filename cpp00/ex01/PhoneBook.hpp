/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:26:43 by mmeising          #+#    #+#             */
/*   Updated: 2022/06/28 18:01:27 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


# include "Contact.hpp"
# include <iostream>
# include <string>

class PhoneBook
{

	public:

		PhoneBook();
		PhoneBook( PhoneBook const & src );
		~PhoneBook();

		Contact contacts[8];

		PhoneBook &		operator=( PhoneBook const & rhs );

	private:

		void	AddContact(
						std::string firstname,
						std::string lastname,
						std::string nickname,
						std::string phonenumber,
						std::string darkestsecret);
		std::string	AddFirstName(std::string firstname);
		
};

std::ostream &			operator<<( std::ostream & o, PhoneBook const & i );

#endif /* ******************************************************* PHONEBOOK_H */