/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:41:12 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/04 19:16:00 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv) {
    std::string s1;
    std::string s2;

    if (argc != 4) {
        std::cout << "usage:\n./replace \"string to be replaced\" \"string to "
                     "replace it with\"\n";
        return (1);
    }
    std::ifstream ifs(argv[1]);
    if (!ifs.is_open()) {
        std::cout << "Failed to open file: " << argv[1] << "\n";
        return (2);
    }
    std::ofstream ofs("some_file.replace");
    ifs.close();
    ofs.close();
}
