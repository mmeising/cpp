/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:28:31 by mmeising          #+#    #+#             */
/*   Updated: 2023/05/13 15:12:26 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

# include <unistd.h>
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: Could not open file.\n";
        return (1);
    }
    (void)argc;
    BitcoinExchange btc(argv[1]);
    btc.printValues();
    return 0;
}
