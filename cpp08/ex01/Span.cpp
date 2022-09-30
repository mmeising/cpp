/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:49:59 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/30 03:37:55 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : cap_(0), current_(0) {}

Span::Span(const Span& src)
    : vec_(src.vec_), cap_(src.cap_), current_(src.current_) {}

Span::Span(unsigned int N) : cap_(N), current_(0) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span& Span::operator=(Span const& rhs) {
    if (this != &rhs) {
        vec_ = std::vector<int>(rhs.vec_);
        cap_ = rhs.cap_;
        current_ = rhs.current_;
    }
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int x) {
    try {
        if (current_ < cap_) {
            vec_.push_back(x);
            current_++;
        } else
            throw std::exception();
    } catch (std::exception& e) {
        std::cout << "Error: Span has no space left\n";
    }
}

int Span::shortestSpan() const {
    std::vector<int>::const_iterator start = vec_.begin();
    std::vector<int>::const_iterator comp;
    std::vector<int>::const_iterator end = vec_.end();
    std::vector<int>::const_iterator second_to_last = end;
    int shortest_span = INT_MAX;
    int temp;

    second_to_last--;
    if (current_ < 2) throw(std::exception());
    while (start != second_to_last) {
        comp = start;
        comp++;
        while (comp != end) {
            temp = *start - *comp;
            if (temp < 0) temp *= -1;
            if (temp < shortest_span) shortest_span = temp;
            comp++;
        }
        start++;
    }
    if (shortest_span == INT_MAX) shortest_span = 0;
    return (shortest_span);
}

int Span::longestSpan() const {
    int max = *(vec_.begin());
    int min = *(vec_.begin());
    std::vector<int>::const_iterator start = vec_.begin();
    std::vector<int>::const_iterator end = vec_.end();

    if (current_ < 2) throw(std::exception());
    while (start != end) {
        if (*start < min) min = *start;
        if (*start > max) max = *start;
        start++;
    }
    return (max - min);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int Span::getCurrent() { return (current_); }
unsigned int Span::getCap() { return (cap_); }

/* ************************************************************************ */