/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:21:50 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/26 15:47:04 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main(void) {
    std::srand((unsigned int)std::time(nullptr));

    for (int i = 0; i < 5; i++) {
        Base* ptr = generate();

        identify(ptr);  //by pointer
        identify(*ptr); //by reference
        std::cout << "\n";
        delete ptr;
    }
}
