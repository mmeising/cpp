/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:56:34 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/13 21:36:43 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void true_or_false(bool a) {
    if (a == true) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
}

int main() {
    {
        //      < > <= >= != ==
        Fixed x;
        Fixed y = 3;
        Fixed z(y);

        x = Fixed(5.5f);
        std::cout << "x = Fixed(5.5f), y = 3:\n\n";
        std::cout << "x < y ";
        true_or_false(x < y);
        std::cout << "x > y ";
        true_or_false(x > y);
        std::cout << "x <= y ";
        true_or_false(x <= y);
        std::cout << "x >= y ";
        true_or_false(x >= y);
        std::cout << "x != y ";
        true_or_false(x != y);
        std::cout << "x == y ";
        true_or_false(x == y);

        x = 3;
        std::cout << "\nx = 3, y = 3:\n\n";
        std::cout << "x < y ";
        true_or_false(x < y);
        std::cout << "x > y ";
        true_or_false(x > y);
        std::cout << "x <= y ";
        true_or_false(x <= y);
        std::cout << "x >= y ";
        true_or_false(x >= y);
        std::cout << "x != y ";
        true_or_false(x != y);
        std::cout << "x == y ";
        true_or_false(x == y);
    }
    {
        //      +  -  *  /
        Fixed result;
        result = Fixed(5.03125f) + Fixed(3.0625f);
        std::cout << "\n5.03125f + 3.0625f = " << result;
        result = Fixed(5.03125f) + Fixed(-3.0625f);
        std::cout << "\n5.03125f + -3.0625f = " << result;

        result = Fixed(5.5f) - Fixed(3.25f);
        std::cout << "\n5.5f - 3.25f = " << result;
        result = Fixed(5.03125f) - Fixed(-3.0625f);
        std::cout << "\n5.03125f - -3.0625f = " << result;

        result = Fixed(2.25f) * Fixed(1.5f);
        std::cout << "\n2.25f * 1.5f = " << result;
        result = Fixed(2.25f) * Fixed(-1.5f);
        std::cout << "\n2.25f * -1.5f  = " << result;

        result = Fixed(2.25f) / Fixed(1.5f);
        std::cout << "\n2.25f / 1.5f = " << result;
        result = Fixed(2.25f) / Fixed(-1.5f);
        std::cout << "\n2.25f / -1.5f  = " << result;
    }
    {
        Fixed x(0);

        std::cout << "\n\nx(0):\n\n";
        std::cout << "x: " << x << "\n";
        std::cout << "++x: " << ++x << "\n";
        std::cout << "x++: " << x++ << "\n";
        std::cout << "x: " << x << "\n\n";

        Fixed y(Fixed(5.05f) * Fixed(2));

        std::cout << "y(Fixed(5.05f) * Fixed(2)):\n\n";
        std::cout << y << "\n";

    }
}
