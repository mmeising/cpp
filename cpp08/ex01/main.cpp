/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:57:23 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/30 03:37:39 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    std::vector<int> vector;
    Span sp_empty(5);
    Span sp_one(7);
    Span sp(40);

    for (int x = 0; x < 500; x += 10) {
        vector.push_back(x);
    }
    sp_one.addNumber(17);

    std::vector<int>::const_iterator start = vector.begin();
    for (int x = 0; x < 10; x++) {
        start++;
    }
    sp.addNumber<std::vector<int> >(start, vector.end());
    std::cout << "sp longest span: " << sp.longestSpan() << "\n";
    std::cout << "sp shortest span: " << sp.shortestSpan() << "\n";
    std::cout << "sp currently holding " << sp.getCurrent() << " from " << sp.getCap() << "\n";

    {
        Span huge(20000);
        std::vector<int> fill(19000, 50);

        huge.addNumber<std::vector<int> >(fill.begin(), fill.end());
        huge.addNumber(10);
        std::cout << "longest: " << huge.longestSpan() << "\n";
    }
}
