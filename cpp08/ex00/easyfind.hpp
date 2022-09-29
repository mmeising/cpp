/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:38:54 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/29 20:34:50 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <string>

template <typename T>
bool easyfind(T container, int const x) {
    typename T::iterator start;
    typename T::iterator end;

    start = container.begin();
    end = container.end();
    while (start != end) {
        if (*start == x) return (true);
        start++;
    }
    // throw(std::exception());
    return (false);
}
//if want to throw an error when it doesn't find the number, remove the return
// values and uncomment the throw
#endif  // EASYFIND_HPP