/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:09:53 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/27 19:59:09 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
    Array <int>arr = Array<int>(12);
    std::cout << "arrays size() returns: " << arr.size() << "\n";
    std::cout << "arr[11]: " << arr[11] << "\n";
    std::cout << "arr[11] = 7\n";
    arr[11] = 7;
    std::cout << "arr[11]: " << arr[11] << "\n";
    std::cout << "\n";

    Array <int>dup = Array <int>(arr);
    std::cout << "dup[11]: " << dup[11] << "\n";
    std::cout << "dup[11] = 2;\n";
    dup[11] = 2;
    std::cout << "dup[11]: " << dup[11] << "\n";
    std::cout << "arr[11]: " << arr[11] << "\n";
    std::cout << "\n";

    std::cout << "arr = dup\n";
    arr = dup;
    std::cout << "dup[11]: " << dup[11] << "\n";
    std::cout << "arr[11]: " << arr[11] << "\n";
    arr[11] = 10;
    std::cout << "dup[11]: " << dup[11] << "\n";
    std::cout << "arr[11]: " << arr[11] << "\n";
    std::cout << "\n";

    try {
        std::cout << "trying to access out of bounds now\n";
        arr[12] = 1;
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }
    std::cout << "\n";
}
