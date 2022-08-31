/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:05:12 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/31 17:06:09 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* catto = new Cat();
    const Animal* doggo = new Dog();
    std::cout << catto->getType() << " " << std::endl;
    std::cout << doggo->getType() << " " << std::endl;
    catto->makeSound(); //will output the cat sound!
    doggo->makeSound(); //will output the dog sound!
    meta->makeSound();

    delete meta;
    delete doggo;
    delete catto;

    system("leaks a.out");
    while (1);

    return 0;
}
