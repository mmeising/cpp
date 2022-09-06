/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:05:12 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/06 17:03:13 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    int n = 4;
    AAnimal* array[n];

    std::cout << "\nstarting for loop:\n";
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            array[i] = new Dog();
            std::cout << "\n";
        } else {
            array[i] = new Cat();
            std::cout << "\n";
        }
    }
    std::cout << "\n\nFinished populating array\n\n";
    for (int i = 0; i < n; i++) {
        delete array[i];
        std::cout << "\n";
    }

    std::cout << "\n\ndeep copy test:\n\n";

    Cat* catto = new Cat();
    catto->getBrain()->setIdea(0, "mice!");

    Cat* copy = new Cat(*catto);
    std::cout << "catto idea[0]: " << catto->getBrain()->getIdea(0) << "\n";
    std::cout << "copy idea[0]: " << copy->getBrain()->getIdea(0) << "\n";

    copy->getBrain()->setIdea(0, "sleeeeeeep...");
    std::cout << "copy idea changed, catto stays the same:"
              << "\n";
    std::cout << "catto idea[0]: " << catto->getBrain()->getIdea(0) << "\n";
    std::cout << "copy idea[0]: " << copy->getBrain()->getIdea(0) << "\n";

    delete catto;
    delete copy;

    // this will not work:
    // AAnimal* abstract = new AAnimal();
    // neither will this work:
    // AAnimal abstracto = AAnimal();

    system("leaks a.out");
    // while (1);
    return 0;
}
