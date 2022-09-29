/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:49:49 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/30 00:16:42 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Span {
   public:
    Span();
    Span(Span const& src);
    Span(unsigned int N);
    ~Span();

    Span& operator=(Span const& rhs);

    void addNumber(int x);

    template <typename T>
    void addRange(typename T::const_iterator start, typename T::const_iterator end);

    int shortestSpan() const;
    int longestSpan() const;

   private:
    std::vector<int> vec_;
    unsigned int cap_;
    unsigned int current_;
};


#endif /* ********************************************************** SPAN_H */