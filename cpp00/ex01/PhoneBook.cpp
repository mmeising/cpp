/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:26:47 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/08 13:18:38 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
using std::string;

PhoneBook::PhoneBook() { i = 0; }
PhoneBook::~PhoneBook() {}

/*
** ------------------------------- ADD Command --------------------------------
*/

static int IsEmpty(std::string str) {
    string comp(str.size(), ' ');

    if (std::memcmp(str.c_str(), comp.c_str(), str.size()) == 0)
        return 1;
    return 0;
}

string PromptType(string type) {
    string ret;

    do {
        std::cout << "Contact's " << type << ": ";
        if (!std::getline(std::cin, ret)) {
            std::exit(0);
        }
    } while (ret.size() == 0 || IsEmpty(ret));
    return ret;
}

void PromptUser(Contact &contact) {
    contact.set_firstname(PromptType("first name"));
    contact.set_lastname(PromptType("last name"));
    contact.set_nickname(PromptType("nickname"));
    contact.set_phone_number(PromptType("phone number"));
    contact.set_secret(PromptType("darkest secret"));
}

void PhoneBook::AddContact() {
    if (i < 8) {
        PromptUser(contacts[i]);
        i++;
    } else {
        for (int j = 0; j < 7; j++) {
            contacts[j] = contacts[j + 1];
        }
        PromptUser(contacts[7]);
    }
}

/*
** ------------------------------ SEARCH Command ------------------------------
*/

static void PrintHeader() {
    std::cout << "---------------------------------------------\n"
              << "|   Entry  |First name| Last name| Nickname |\n"
              << "---------------------------------------------\n";
}

static void PrintWide(std::string string) {
    if (string.size() > 10) {
        std::cout << string.substr(0, 9) << ".";
    } else {
        std::cout << std::setw(10) << string;
    }
    std::cout << "|";
}

static void PrintRow(const Contact &contact, int i) {
    std::cout << "|" << std::setw(10) << i << "|";
    PrintWide(contact.get_firstname());
    PrintWide(contact.get_lastname());
    PrintWide(contact.get_nickname());
    std::cout << "\n";
}

static void PrintEntry(const Contact &contact) {
    std::cout << "First Name: " << contact.get_firstname() << "\n"
              << "Last Name: " << contact.get_lastname() << "\n"
              << "Nickname: " << contact.get_nickname() << "\n"
              << "Phone number: " << contact.get_phone_number() << "\n"
              << "Darkest secret: " << contact.get_secret() << "\n";
}

void PhoneBook::Search() const {
    string string;
    PrintHeader();
    for (int i = 0; i < 8; i++) {
        PrintRow(contacts[i], i + 1);
    }
    std::cout << "---------------------------------------------\n";
    std::cout << "Which entry do you want to see? ";
    if (!std::getline(std::cin, string)) {
        std::exit(0);
    }
    if (string.size() != 1 || atoi(string.c_str()) < 1 ||
        atoi(string.c_str()) > 8) {
        std::cout << "Not a valid index. Returning to main menu\n";
    } else {
        PrintEntry(contacts[atoi(string.c_str()) - 1]);
    }
}
