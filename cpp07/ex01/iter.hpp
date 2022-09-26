/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:40:20 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/26 23:00:27 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T* ptr_arr, size_t array_length, void(*f)(T&)) {
    if (ptr_arr == nullptr || f == nullptr)
        return;
    for (size_t i = 0; i < array_length; i++) {
        f(ptr_arr[i]);
    }
}

#endif // ITER_HPP