/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:18:13 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/02 20:34:45 by mmeising         ###   ########.fr       */
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

/*
** ------------------------------- All Accounts -------------------------------
*/

int Account::getNbAccounts(void) { return Account::_nbAccounts; }
int Account::getTotalAmount(void) { return Account::_totalAmount; }
int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount() 
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals() << "\n";
}

/*
** ----------------------------- (De-)Constructor -----------------------------
*/

Account::Account(void) {
    _accountIndex = Account::_nbAccounts++;
    _amount = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";created\n";
}

Account::Account(int initial_deposit) {
    _accountIndex = Account::_nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";created\n";
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";closed\n";
}

/*
** ------------------------------- One Account --------------------------------
*/

void	Account::makeDeposit( int deposit ) {
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit
              << ";deposit:" << deposit << ";amount:" << _amount 
              << ";nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount 
              << ";withdrawal:";
    if (_amount >= withdrawal) {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << withdrawal << ";amount:" << _amount 
                  << ";nb_withdrawals:" << _nbWithdrawals << "\n";
    } else {
        std::cout << "refused\n";
        return 1;
    }
    return 0;
}

int		Account::checkAmount( void ) const { return _amount; }

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << "\n";
}

/*
** --------------------------------- Utility ----------------------------------
*/

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
    std::cout << "] ";
}
