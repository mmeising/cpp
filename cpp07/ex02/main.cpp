/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:09:53 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/27 00:06:21 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
    Array <int>arr = Array<int>(12);
    std::cout << "arrays size() returns: " << arr.size() << "\n";
    std::cout << "arr[11]: " << arr[11] << "\n";
    arr[11] = 7;
    std::cout << "arr[11]: " << arr[11] << "\n";
    std::cout << "\n";

    Array <int>dup = Array <int>(arr);
    std::cout << "dup[11]: " << dup[11] << "\n";
    dup[11] = 2;
    std::cout << "dup[11]: " << dup[11] << "\n";
    std::cout << "arr[11]: " << arr[11] << "\n";
    std::cout << "\n";

    arr = dup;
    std::cout << "dup[11]: " << dup[11] << "\n";
    std::cout << "arr[11]: " << arr[11] << "\n";
    arr[11] = 10;
    std::cout << "dup[11]: " << dup[11] << "\n";
    std::cout << "arr[11]: " << arr[11] << "\n";

}
