/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:49:15 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/15 01:18:55 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Point pa(point.getX().toFloat() - a.getX().toFloat(),
             point.getY().toFloat() - a.getY().toFloat());
    Point pb(point.getX().toFloat() - b.getX().toFloat(),
             point.getY().toFloat() - b.getY().toFloat());
    Point pc(point.getX().toFloat() - c.getX().toFloat(),
             point.getY().toFloat() - c.getY().toFloat());

    float side_ab =
        ((b.getX().toFloat() - a.getX().toFloat()) * pa.getY().toFloat() -
        (b.getY().toFloat() - a.getY().toFloat()) * pa.getX().toFloat());
    float side_bc =
        (c.getX().toFloat() - b.getX().toFloat()) * pb.getY().toFloat() -
        (c.getY().toFloat() - b.getY().toFloat()) * pb.getX().toFloat();
    float side_ca =
        (a.getX().toFloat() - c.getX().toFloat()) * pc.getY().toFloat() -
        (a.getY().toFloat() - c.getY().toFloat()) * pc.getX().toFloat();

    if (side_ab == 0.0f || side_bc == 0.0f || side_ca == 0.0f) {
        return false;
    } else if (side_ab > 0.0f && side_bc > 0.0f && side_ca > 0.0f) {
        return true;
    } else if (side_ab < 0.0f && side_bc < 0.0f && side_ca < 0.0f) {
        return true;
    }
    return false;
}
