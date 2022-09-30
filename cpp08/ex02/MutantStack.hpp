/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 03:40:49 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/30 06:48:49 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <string>

template <class T>
class MutantStack : public std::stack<T> {
   public:
    MutantStack() : std::stack<T>(){};
    MutantStack(std::stack<T> const& src) : std::stack<T>(src){};
    ~MutantStack(){};

    std::stack<T>& operator=(const std::stack<T>& src) {
        if (*this != src) {
            *this = src;
        }
        return (*this);
    }

    typename std::stack<T>::container_type::iterator begin() {
        return (std::stack<T>::c.begin());
    };

    typename std::stack<T>::container_type::iterator end() {
        return (std::stack<T>::c.end());
    };

   private:
};

#endif  // MUTANTSTACK_HPP