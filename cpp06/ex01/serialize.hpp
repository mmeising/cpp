/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:59:36 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/26 14:08:36 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iomanip>
#include <iostream>
#include <string>

struct Data {
    int int_val;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif //SERIALIZE_HPP