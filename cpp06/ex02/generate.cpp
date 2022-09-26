/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:22:20 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/26 16:05:18 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* generate(void) {
    switch(std::rand() % 3) {
        case 0:
            return (new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
        default:
            std::cout << "rand() went wrong\n";
            return nullptr;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A\n";
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B\n";
    } else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "???\n";
}

void identify(Base& p) {
    void* x = nullptr;
    Base& y = reinterpret_cast<Base&>(x);

    try {
        y = dynamic_cast<A&>(p);
        std::cout << "A\n";
    } catch (std::exception& e) {
        try {
            y = dynamic_cast<B&>(p);
            std::cout << "B\n";
        } catch (std::exception& e) {
            try {
                y = dynamic_cast<C&>(p);
                std::cout << "C\n";
            } catch (std::exception& e) {
                std::cout << "Couldn't find type: " << e.what() << "\n";
            }
        }
    }
}
