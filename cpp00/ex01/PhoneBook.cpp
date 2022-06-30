/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:26:47 by mmeising          #+#    #+#             */
/*   Updated: 2022/06/30 04:43:09 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
using std::string;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PhoneBook::PhoneBook() { i = 0; }

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PhoneBook::~PhoneBook() {}

/*
** --------------------------------- METHODS ----------------------------------
*/

Contact PhoneBook::PromptUser() {
    Contact contact;
    string temp;

    std::cout << "Contact's first name: ";
    // std::getline(std::cin, temp);
    std::cin >> temp;
    std::cin.ignore(1000, '\n');
    contact.set_firstname(temp);
    std::cout << "Contact's last name: ";
    // std::getline(std::cin, temp);
    std::cin >> temp;
    std::cin.ignore(1000, '\n');
    contact.set_lastname(temp);
    std::cout << "Contact's nickname: ";
    // std::getline(std::cin, temp);
    std::cin >> temp;
    std::cin.ignore(1000, '\n');
    contact.set_nickname(temp);
    std::cout << "Contact's phone number: ";
    // std::getline(std::cin, temp);
    std::cin >> temp;
    std::cin.ignore(1000, '\n');
    contact.set_phone_number(temp);
    std::cout << "Contact's darkest secret: ";
    // std::getline(std::cin, temp);
    std::cin >> temp;
    std::cin.ignore(1000, '\n');
    contact.set_secret(temp);
    return contact;
}

void PhoneBook::AddContact() {
    if (i < 8) {
        contacts[i] = PromptUser();
        i++;
    } else {
        for (int j = 0; j < 6; j++) {
            contacts[j] = contacts[j + 1];
        }
        contacts[7] = PromptUser();
    }
}

static void PrintWide(std::string string) {
    if (string.size() > 10) {
        std::cout << string.substr(0, 9) << ".";
    } else {
        std::cout << std::setw(10) << string;
    }
    std::cout << "|";
}

static void PrintRow(Contact contact, int i) {
    std::cout << "|" << std::setw(10) << i << "|";
    PrintWide(contact.get_firstname());
    PrintWide(contact.get_lastname());
    PrintWide(contact.get_nickname());
    std::cout << "\n";
}

static void PrintInfo(Contact contact) {
    std::cout << "First Name: " << contact.get_firstname() << "\n"
              << "Last Name: " << contact.get_lastname() << "\n"
              << "Nickname: " << contact.get_nickname() << "\n"
              << "Phone number: " << contact.get_phone_number() << "\n"
              << "Darkest secret: " << contact.get_secret() << "\n";
}

void PhoneBook::Search() const {
    string string;
    for (int i = 0; i < 8; i++) {
        PrintRow(contacts[i], i + 1);
    }
    std::cout << "Which entry do you want to see? ";
    std::getline(std::cin, string);
    if (string.size() != 1 || atoi(string.c_str()) < 1 ||
        atoi(string.c_str()) > 8) {
        std::cout << "Not a valid index. Returning to main menu\n";
    } else {
        PrintInfo(contacts[atoi(string.c_str()) - 1]);
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */