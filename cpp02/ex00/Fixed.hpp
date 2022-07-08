/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:13:48 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/08 18:28:39 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
   public:
    Fixed();
    Fixed(Fixed const& src);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);

    Fixed& operator=(Fixed const& rhs);

   private:
    int val_;                     // fixed point number value
    static const int fract = 8;  // number of fractional bits
};

// std::ostream& operator<<(std::ostream& o, Fixed const& i);

#endif /* ********************************************************* FIXED_H */