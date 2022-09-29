/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:38:37 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/29 20:44:58 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>

#include "easyfind.hpp"

int main(void) {
    {
        std::list<int> list;

        for (int x = 0; x < 5; x++) {
            list.push_back(x);
        }
        if (easyfind(list, 2)) {
            std::cout << "Found the 2\n";
        } else 
            std::cout << "Didn't find the 2\n";
        if (easyfind(list, 7)) {
            std::cout << "Found the 7\n";
        } else 
            std::cout << "Didn't find the 7\n";
    }
    std::cout << "\n";
    {
        std::vector<int> vector;

        for (int x = 0; x < 5; x++) {
            vector.push_back(x);
        }
        if (easyfind(vector, 2)) {
            std::cout << "Found the 2\n";
        } else 
            std::cout << "Didn't find the 2\n";
        if (easyfind(vector, 7)) {
            std::cout << "Found the 7\n";
        } else 
            std::cout << "Didn't find the 7\n";
    }
}
