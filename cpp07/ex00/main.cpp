/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:04:36 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/26 19:39:08 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void) {
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }

    std::cout << "\nEnd of Subject examples\n\n";

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
