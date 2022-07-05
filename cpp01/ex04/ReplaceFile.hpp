/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFile.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:17:53 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/05 20:01:02 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACEFILE_HPP
#define REPLACEFILE_HPP

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

class ReplaceFile {
   public:
    int readFromFile();
    int writeToFile();
    void replaceStrings();

    ReplaceFile();
    ReplaceFile(ReplaceFile const& src);
    ~ReplaceFile();

    std::string getFile();
    std::string getSearch();
    std::string getReplace();
    void setFile(std::string file);
    void setSearch(std::string search);
    void setReplace(std::string replace);
    int setValues(int argc, char** argv);

    std::string content_;

   private:
    std::string file_;
    std::string search_;
    std::string replace_;
};

std::ostream& operator<<(std::ostream& o, ReplaceFile const& i);

#endif /* *************************************************** REPLACEFILE_H */