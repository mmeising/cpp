/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:33:42 by mmeising          #+#    #+#             */
/*   Updated: 2022/06/28 17:33:45 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{

	public:

		Contact();
		Contact( Contact const & src );
		~Contact();

		Contact &		operator=( Contact const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, Contact const & i );

#endif /* ********************************************************* CONTACT_H */