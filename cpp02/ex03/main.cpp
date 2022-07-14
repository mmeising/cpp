/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 21:47:17 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/15 01:18:24 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

void true_or_false(bool a) {
    if (a == true) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
}

void test_relational() {
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

void test_arithmetic() {
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

void test_crement() {
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

void test_min_max() {
    Fixed x(5.25f);
    Fixed y(5.125f);
    Fixed const cx(1.5f);
    Fixed const cy(1.125f);

    std::cout << "x(5.25f), y(5.125f)\n";
    std::cout << "min(x, y): ";
    std::cout << Fixed::min(x, y);
    std::cout << "\nmax(x, y): ";
    std::cout << Fixed::max(x, y);

    std::cout << "\n\nconst cx(1.5f), const cy(1.125f)\n";
    std::cout << "min(cx, cy): ";
    std::cout << Fixed::min(cx, cy);
    std::cout << "\nmax(cx, cy): ";
    std::cout << Fixed::max(cx, cy);
    std::cout << "\n\n";
}

void test_triangles() {
    bool first = bsp(Point(1.0f, 1.0f),
                     Point(1.0f, 4.0f),
                     Point(4.0f, 1.0f),
                     Point(1.0f, 2.0f));
    if (first) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }

    bool sec = bsp(Point(1.0f, 1.0f),
                   Point(1.0f, 4.0f),
                   Point(4.0f, 1.0f),
                   Point(1.1f, 2.0f));
    if (sec) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }

    bool third = bsp(Point(-1.0f, -1.0f),
                     Point(-1.0f, -4.0f),
                     Point(-4.0f, -1.0f),
                     Point(-1.0f, -2.0f));
    if (third) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }

    bool fourth = bsp(Point(-1.0f, -1.0f),
                      Point(-1.0f, -4.0f),
                      Point(-4.0f, -1.0f),
                      Point(-1.1f, -2.0f));
    if (fourth) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
}

int main() {
    test_relational();
    test_arithmetic();
    test_crement();
    test_min_max();
    test_triangles();
}