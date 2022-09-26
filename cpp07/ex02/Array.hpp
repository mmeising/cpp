/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:07:12 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/27 00:06:52 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array {
   public:
    Array() {
        std::cout << "Array default constructor called\n";
        arr_ = new T[0];
        size_ = 0;
    };

    Array(unsigned int n) {
        std::cout << "Array unsigned int constructor with n = " << n
                  << " called\n";
        arr_ = new T[n];
        size_ = n;
    };

    Array(Array const& src) {
        std::cout << "Array copy constructor called\n";
        arr_ = new T[src.size()];
        for (unsigned int i = 0; i < src.size(); i++) {
            arr_[i] = T(src.arr_[i]);
        }
        size_ = src.size();
    };

    ~Array() {
        std::cout << "Array default destructor called\n";
        delete[] arr_;
    };

    T& operator=(Array const& rhs) {
        std::cout << "Array assignment operator called\n";
        arr_ = new T[rhs.size()];
        for (unsigned int i = 0; i < rhs.size(); i++) {
            arr_[i] = T(rhs.arr_[i]);
        }
        size_ = rhs.size();
        return *this;
    };

    T& operator[](std::size_t id) {
        if (id < size()) {
            return arr_[id];
        } else
            throw std::exception();
    };

    std::size_t size(void) const { return size_; };

   private:
    T* arr_;
    std::size_t size_;
};

#endif  // ARRAY_HPP