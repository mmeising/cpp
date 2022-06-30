/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:33:53 by mmeising          #+#    #+#             */
/*   Updated: 2022/06/30 04:32:34 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	line;
    PhoneBook   phone_book;

	while (1)
	{
		std::cout << "commands are: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, line);
		if (line.compare("ADD") == 0) {
            phone_book.AddContact();
		}
		else if (line.compare("SEARCH") == 0) {
            phone_book.Search();
		}
		else if (line.compare("EXIT") == 0) {
            return (0);
		}
	}
}
