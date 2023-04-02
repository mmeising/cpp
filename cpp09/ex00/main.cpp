/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:28:31 by mmeising          #+#    #+#             */
/*   Updated: 2023/04/02 19:11:38 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

# include <unistd.h>
int main(int argc, char** argv) {
    // (void)argc;
    // (void)argv;
    // std::string str1("2021-09-01");
    // std::string str2("2021-08-31");
    // if (str1.compare(str2) < 0) // is true when str2 is smaller than s1
    //     std::cout << "str1.comp(str2) is true\n";
    // else
    //     std::cout << "comp false\n";

    if (argc != 2) {
        std::cerr << "Error: Could not open file.\n";
        return (1);
    }
    (void)argc;
    std::cout << "Argv[1] is " << argv[1] << std::endl;
    BitcoinExchange btc(argv[1]);
    // btc.setDatabase(argv[1]);

    // btc.printPairList(btc.getDatabase());
    // btc.printPairList(btc.getInput());
    btc.printValues();
    return 0;
}
