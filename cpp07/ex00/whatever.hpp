/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:05:06 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/26 19:37:39 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T& x, T& y) {
    T temp = x;

    x = y;
    y = temp;
}

template <typename T>
T const& min(T const& x, T const& y) {
    return (x < y ? x : y);
}

template <typename T>
T const& max(T const& x, T const& y) {
    return (y < x ? x : y);
}

#endif  // WHATEVER_HPP