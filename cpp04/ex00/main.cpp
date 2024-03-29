/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:05:12 by mmeising          #+#    #+#             */
/*   Updated: 2022/08/30 16:54:29 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound(); //will output the dog sound!
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "Wrong stuff now:\n\n";

    const WrongAnimal* Wmeta = new WrongAnimal();
    const WrongAnimal* Wi = new WrongCat();

    std::cout << Wi->getType() << " " << std::endl;

    Wi->makeSound();
    Wmeta->makeSound();

    delete Wmeta;
    delete Wi;

    return 0;
}
