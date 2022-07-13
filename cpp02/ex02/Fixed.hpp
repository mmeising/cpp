/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:55:27 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/13 21:21:44 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <string>

//  Keep in mind that with 8 bits for the value after the decimal point, the
//  lowest increments Fixed numbers can do is 1 / 2^8 = 1 / 256 = 0.00390625.
//  It will always round down to the next multiple of that fraction.
class Fixed {
   public:
    Fixed();
    Fixed(const int input);
    Fixed(const float input);
    Fixed(Fixed const& src);
    ~Fixed();

    float toFloat() const;
    int toInt() const;

    int getRawBits() const;
    void setRawBits(int const raw);

    Fixed& operator=(Fixed const& rhs);

    // Comparison operators

    bool operator<(Fixed& rhs);
    bool operator>(Fixed& rhs);
    bool operator>=(Fixed& rhs);
    bool operator<=(Fixed& rhs);
    bool operator!=(Fixed& rhs);
    bool operator==(Fixed& rhs);

    // Arithmetic operators

    Fixed operator+(Fixed const& rhs);
    Fixed operator-(Fixed const& rhs);
    Fixed operator*(Fixed const& rhs);
    Fixed operator/(Fixed const& rhs);

    // // In-/Decrement

    Fixed& operator++();
    Fixed operator++(int n);
    Fixed& operator--();
    Fixed operator--(int n);

    // Min/Max

    Fixed& min(Fixed& a, Fixed& b);
    Fixed& max(Fixed& a, Fixed& b);
    Fixed& min(Fixed const& a, Fixed const& b);
    Fixed& max(Fixed const& a, Fixed const& b);

   private:
    int val_;                     // fixed point number value
    static const int fract_ = 8;  // number of fractional bits
    static bool messages_;
};

std::ostream& operator<<(std::ostream& o, Fixed const& i);

#endif /* ********************************************************* FIXED_H */