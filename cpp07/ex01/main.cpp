/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:41:15 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/26 23:05:54 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print_stuff(std::string& str) {
    std::cout << str << "\n";
}

template <typename T>
void print_template(T& comp) {
    std::cout << "template is " << comp;
    std::cout << "\n";
}

int main(void) {
    std::string arr[] = {"a", "b", "c"};
    int arr_int[] = {17, 7, 70};

    iter(arr, static_cast<size_t>(3), &print_stuff);
    iter(arr, 3, &print_template);
    iter(arr_int, 3, &print_template);
}
