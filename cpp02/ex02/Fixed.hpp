/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:55:27 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/12 17:25:33 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <string>

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

    bool operator<(Fixed& const rhs);
    bool operator>(Fixed& const rhs);
    bool operator>=(Fixed& const rhs);
    bool operator<=(Fixed& const rhs);
    bool operator!=(Fixed& const rhs);
    bool operator==(Fixed& const rhs);

    // Arithmetic operators

    Fixed& operator+(Fixed const& rhs);
    Fixed& operator-(Fixed const& rhs);
    Fixed& operator*(Fixed const& rhs);
    Fixed& operator/(Fixed const& rhs);

    // In-/Decrement

    Fixed& operator++();
    Fixed& operator++(Fixed const& rhs);
    Fixed& operator--();
    Fixed& operator--(Fixed const& rhs);

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