/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:59:00 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/26 14:14:50 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

int main(void) {
    Data* ptr;
    Data data;
    uintptr_t serialized;

    data.int_val = 5;
    std::cout<< &data << " Data address, " 
              << ", Datas int_val: " << data.int_val << "\n";

    serialized = serialize(&data);
    std::cout << serialized << " address after serialize\n";

    ptr = deserialize(serialized);
    std::cout << ptr << " address after deserialize, "
              << ", value saved there: " << ptr->int_val << "\n";
}
