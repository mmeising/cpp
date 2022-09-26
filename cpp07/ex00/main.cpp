/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:04:36 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/26 19:37:13 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void) {
    int x = 5;
    int y = 10;

    float fx = 3.5f;
    float fy = 7.2f;

    std::cout << "x: " << x << " y: " << y << "\n";
    std::cout << "swap(x, y)\n";
    swap<int>(x, y);
    std::cout << "x: " << x << " y: " << y << "\n";
    std::cout << "min(x, y): " << min<int>(x, y) << "\n";
    std::cout << "max(x, y): " << max<int>(x, y) << "\n";

    std::cout << "\n";

    std::cout << "fx: " << fx << " fy: " << fy << "\n";
    std::cout << "swap(fx, fy)\n";
    swap<float>(fx, fy);
    std::cout << "fx: " << fx << " fy: " << fy << "\n";
    std::cout << "min(fx, fy): " << min<float>(fx, fy) << "\n";
    std::cout << "max(fx, fy): " << max<float>(fx, fy) << "\n";
}
