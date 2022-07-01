/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:18:13 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/01 04:33:58 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <time.h>

#include <iomanip>
#include <iostream>
using std::string;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void) {
    time_t raw_time;
    struct tm* ptm;
    string temp;

    time(&raw_time);
    ptm = gmtime(&raw_time);
    std::cout << "[" << ptm->tm_year + 1900;
    std::cout << std::setfill('0') << std::setw(2);
    std::cout << ptm->tm_mon + 1;
    std::cout << std::setfill('0') << std::setw(2);
    std::cout << ptm->tm_mday;
    std::cout << "_";
    std::cout << std::setfill('0') << std::setw(2);
    std::cout << ptm->tm_hour;
    std::cout << std::setfill('0') << std::setw(2);
    std::cout << ptm->tm_min;
    std::cout << std::setfill('0') << std::setw(2);
    std::cout << ptm->tm_sec;
    std::cout << "]";
}

Account::Account(int initial_deposit) {
    _accountIndex = Account::_nbAccounts++;
    _amount = initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit
              << ";created\n";
}

Account::Account(void) {}
Account::~Account(void) {}

// int Account::getNbAccounts(void) { return _nbAccounts; }
// int Account::getTotalAmount(void) { return _totalAmount; }
// int Account::getNbDeposits(void) { return _totalNbDeposits; }
// int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }
// void Account::displayAccountsInfos(void) {}
