/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:52:23 by mmeising          #+#    #+#             */
/*   Updated: 2022/06/28 13:01:26 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string	str_toupper(std::string input)
{
	for (size_t i = 0; input[i]; i++)
		input[i] = std::toupper(input[i]);
	return (input);
}

int	main(int argc, char **argv)
{
	std::string	string;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	string = "";
	for (size_t i = 1; argv[i]; i++)
		string += str_toupper(argv[i]);
	std::cout << string << std::endl;
	return (0);
}
