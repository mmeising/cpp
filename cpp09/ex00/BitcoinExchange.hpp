#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <sstream>

class BitcoinExchange {
    typedef std::list<std::pair<std::string, float> > list;
    typedef std::pair<std::string, float>             pair;

   public:
    BitcoinExchange(std::string input);
    BitcoinExchange(BitcoinExchange const& src);
    ~BitcoinExchange();

    BitcoinExchange& operator=(BitcoinExchange const& rhs);

    BitcoinExchange::list getDatabase() const;
    BitcoinExchange::list getInput() const;
    bool getFilled() const;
    bool setDatabase(BitcoinExchange::list& lst, std::string const filename, char delimiter, bool check_date);

    void printValues() const;
    void printPairList(BitcoinExchange::list database);

   private:
    BitcoinExchange();

    BitcoinExchange::list::const_iterator findPrevDate(std::string const& date) const;

    BitcoinExchange::list database_;
    BitcoinExchange::list input_;
    bool                                      filled_;
};

#endif /* *********************************************** BITCOINEXCHANGE_H */
