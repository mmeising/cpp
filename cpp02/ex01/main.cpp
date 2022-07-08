/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:43:24 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/08 22:38:46 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int main(void) {
    {
        Fixed a;
        Fixed const b(10);
        Fixed const c(42.42f);
        Fixed const d(b);

        a = Fixed(1234.4321f);
        std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
        std::cout << "c is " << c << std::endl;
        std::cout << "d is " << d << std::endl;
        std::cout << "a is " << a.toInt() << " as integer" << std::endl;
        std::cout << "b is " << b.toInt() << " as integer" << std::endl;
        std::cout << "c is " << c.toInt() << " as integer" << std::endl;
        std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    }
    std::cout << "\nNegative numbers:\n\n";
    {
        Fixed a;
        Fixed const b(-10);
        Fixed const c(-42.42f);
        Fixed const d(b);

        a = Fixed(-1234.4321f);
        std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
        std::cout << "c is " << c << std::endl;
        std::cout << "d is " << d << std::endl;
        std::cout << "a is " << a.toInt() << " as integer" << std::endl;
        std::cout << "b is " << b.toInt() << " as integer" << std::endl;
        std::cout << "c is " << c.toInt() << " as integer" << std::endl;
        std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    }
    std::cout << "\nAnd overflows:\n\n";
    {
        Fixed x(81002003);
        Fixed y(42000000.42f);
        std::cout << "x is " << x << std::endl;
        std::cout << "y is " << y << std::endl;
        std::cout << "x is " << x.toInt() << " as integer" << std::endl;
        std::cout << "y is " << y.toInt() << " as integer" << std::endl;
    }
    return 0;
}
