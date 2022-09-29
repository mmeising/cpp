/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:57:23 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/30 00:18:28 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    std::vector<int> vector;
    Span sp_empty(5);
    Span sp_one(7);
    Span sp(60);

    for (int x = 0; x < 500; x += 10) {
        vector.push_back(x);
    }
    sp_one.addNumber(17);

    std::vector<int>::const_iterator start = vector.begin();
    std::vector<int>::const_iterator end = vector.end();
    for (int x = 0; x < 10; x++) {
        start++;
    }
    sp.addRange<std::vector<int> >(start, end);

    std::cout << "sp longest span: " << sp.longestSpan() << "\n";
    std::cout << "sp shortest span: " << sp.shortestSpan() << "\n";
}
