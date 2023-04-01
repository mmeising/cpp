/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniski <mniski@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:46:12 by mniski            #+#    #+#             */
/*   Updated: 2023/04/01 23:28:25 by mniski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string input) : filled_(false) {
    std::cout << "Constructor argument is " << input << std::endl;
    if (!setDatabase(database_, "data.csv", ',', true))
        return;
    if (!setDatabase(input_, input, '|', false))
        return;
    filled_ = true;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
    database_ = src.getDatabase();
    input_    = src.getInput();
    filled_   = src.getFilled();
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs) {
    if ( this != &rhs )
    {
    this->database_ = rhs.getDatabase();
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

BitcoinExchange::list BitcoinExchange::getDatabase() const {
    return database_;
}

BitcoinExchange::list BitcoinExchange::getInput() const {
    return input_;
}

bool BitcoinExchange::getFilled() const {
    return filled_;
}

bool isValidDate(std::string date) {
    int year, month, day;

    if (std::sscanf(date.c_str(), " %d-%d-%d ", &year, &month, &day) != 3)
        return (false);
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return (false);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            if (day > 29)
                return (false);
        } else {
            if (day > 28)
                return (false);
        }
    }
    return (true);
}

bool BitcoinExchange::setDatabase(BitcoinExchange::list& lst, std::string const filename, char delimiter, bool check_date) {
    std::cout << "Called setDatabase with " << filename << std::endl;

    std::ifstream   file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "." << std::endl;
        return (false);
    }
    std::string     line;

    while (getline(file, line)) {
        size_t      pos      = line.find(delimiter);
        std::string date_str = line.substr(0, pos);
        std::string val_str  = line.substr(pos + 1);

        if (line == "date | value" || line == "date,exchange_rate") {
            line.clear();
            continue;
        }
        if (check_date && !isValidDate(date_str)) {
            std::cout << "Invalid date in " << filename << ": " << date_str << std::endl;
            continue;
        }

        std::stringstream ss(val_str);
        float val;
        ss >> val;
        if (pos == std::string::npos)
            val = -1;
        // if (delimiter == '|' && (val < 0 || val > 1000))
        //     continue;

        lst.push_back(std::make_pair(date_str, val));
        line.clear();
    }
    file.close();
    return (true);
}

/**
 * @returns Iterator to highest date datapoint which is still lower than input date.
 * @returns If all dates are higher than input date, returns database_.end()
*/
BitcoinExchange::list::const_iterator BitcoinExchange::findPrevDate(std::string const& date) const {
    BitcoinExchange::list::const_iterator it_db  = database_.begin();

    while (it_db->first.compare(date) < 0 && it_db != database_.end())
        it_db++;
    if (it_db == database_.begin())
        return (database_.end());
    it_db--;
    return (it_db);
}

void BitcoinExchange::printValues() const {
    BitcoinExchange::list::const_iterator it_in = input_.begin();
    BitcoinExchange::list::const_iterator it_db;

    for (; it_in != input_.end(); it_in++) {
        if (!isValidDate(it_in->first)) {
            std::cout << "Error: bad input => " << it_in->first << std::endl;
            continue;
        }
        if (it_in->second > 10000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        if (it_in->second < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        it_db = findPrevDate(it_in->first);
        if (it_db == database_.end()) {//no date lower than input found
            std::cout << "Error: no datapoint with date before this found." << std::endl;
            continue;
        } else {
            std::cout << it_in->first << " => " << it_in->second * it_db->second << std::endl;
        }
    }
}

// void BitcoinExchange::setInput(std::string const input_filename) {
//     std::ifstream   input_file(input_filename.c_str());
//     std::string     line;

//     while (getline(input_file, line)) {
//         size_t      pos      = line.find('|');
//         std::string date_str = line.substr(0, pos);
//         std::string val_str  = line.substr(pos + 1);

//         if (!isValidDate(date_str)) {
//             std::cout << "Invalid date: " << date_str << std::endl;
//         }
//     }
// }

void BitcoinExchange::printPairList(BitcoinExchange::list database) {
    for (BitcoinExchange::list::const_iterator it = database.begin(); it != database.end(); ++it) {
        BitcoinExchange::pair const& pair = *it;
        std::cout << "getting " << pair.first << ", " << pair.second << std::endl;
    }

}

/* ************************************************************************** */