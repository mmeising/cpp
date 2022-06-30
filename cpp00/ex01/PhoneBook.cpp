/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:26:47 by mmeising          #+#    #+#             */
/*   Updated: 2022/06/30 04:53:24 by mmeising         ###   ########.fr       */
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

string PromptType(string type) {
    string ret;

    do {
        std::cout << "Contact's " << type << ": ";
        std::getline(std::cin, ret);
    } while (ret.size() == 0);
    return ret;
}

Contact PhoneBook::PromptUser() {
    Contact contact;

    contact.set_firstname(PromptType("first name"));
    contact.set_lastname(PromptType("last name"));
    contact.set_nickname(PromptType("nickname"));
    contact.set_phone_number(PromptType("phone number"));
    contact.set_secret(PromptType("darkest secret"));
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