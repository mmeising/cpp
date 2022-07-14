/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:45:15 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/15 00:32:19 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>

#include "Fixed.hpp"

class Point {
   public:
    Point();
    Point(const float x, const float y);
    Point(Point const& src);
    ~Point();

    const Fixed& getX() const;
    const Fixed& getY() const;

    Point& operator=(Point const& rhs);

   private:
    Fixed const x_;
    Fixed const y_;
    static bool messages_;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif /* ********************************************************* POINT_H */