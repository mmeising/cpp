/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:00:37 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/05 20:03:58 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceFile.hpp"

ReplaceFile::ReplaceFile() {}
ReplaceFile::~ReplaceFile() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream& operator<<(std::ostream& o, ReplaceFile const& i) {
    o << i.content_;
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int ReplaceFile::readFromFile() {
    std::ifstream ifs(file_);

    if (!ifs.is_open()) {
        std::cerr << "Failed to open file: " << file_ << "\n";
        return 1;
    }
    std::getline(ifs, content_, '\004');
    ifs.close();
    return 0;
}

int ReplaceFile::writeToFile() {
    std::ofstream ofs(getFile() + ".replace");

    if (!ofs.is_open()) {
        std::cerr << "Failed to open file: " << file_ + ".replace\n";
        return 1;
    }
    ofs << content_;
    ofs.close();
    return 0;
}

void ReplaceFile::replaceStrings() {
    size_t i;

    i = content_.find(getSearch(), 0);
    while (i < content_.size()) {
        content_.erase(i, getSearch().size());
        content_.insert(i, getReplace());
        i += getReplace().size();
        i = content_.find(getSearch(), i);
    }
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ReplaceFile::getFile() { return file_; }
std::string ReplaceFile::getSearch() { return search_; }
std::string ReplaceFile::getReplace() { return replace_; }

/*
** --------------------------------- MUTATOR ----------------------------------
*/

void ReplaceFile::setFile(std::string file) { file_ = file; }
void ReplaceFile::setSearch(std::string search) { search_ = search; }
void ReplaceFile::setReplace(std::string replace) { replace_ = replace; }

int ReplaceFile::setValues(int argc, char** argv) {
    if (argc != 4 || !*argv[1] || !*argv[2]) {
        std::cerr
            << "usage:\n./replace \"string to be replaced\" "
               "\"string to replace it with\"\n"
               "important: input file and searched string can't be empty\n";
        return 1;
    }
    this->setFile(argv[1]);
    this->setSearch(argv[2]);
    this->setReplace(argv[3]);
    return 0;
}

/* ************************************************************************** */