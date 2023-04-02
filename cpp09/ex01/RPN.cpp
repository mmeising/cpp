/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:14:44 by mmeising          #+#    #+#             */
/*   Updated: 2023/04/02 22:00:26 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const& src) {
    stack_ = src.stack_;
}

RPN::~RPN() {}

RPN& RPN::operator=(RPN const& rhs) {
    if ( this != &rhs ) {
        stack_ = rhs.stack_;
    }
    return (*this);
}

/**
 * @returns true on success, false on failure.
*/
bool RPN::calc(std::string input) {
    float first;
    float second;
    float result;

    if (stack_.size() < 2) {
        std::cout << "Error: Not enough input numbers for operation of " << input << std::endl;
        return (false);
    }
    second = stack_.top();
    stack_.pop();
    first = stack_.top();
    stack_.pop();

    if (input[0] == '+')
        result = first + second;
    else if (input[0] == '-')
        result = first - second;
    else if (input[0] == '*')
        result = first * second;
    else if (input[0] == '/')
        result = first / second;
    stack_.push(result);
    return (true);
}

/**
 * @returns true on success, false on failure.
*/
bool RPN::input(std::string input) {
    if (input.size() == 1 && input[0] >= '0' && input[0] <= '9') {
        stack_.push(input[0] - '0');
    } else if (input.size() == 1 && input.find("+-*/")) {
        if (!calc(input))
            return (false);
    } else {
        std::cout << "Error: Invalid input: " << input << std::endl;
        return (false);
    }
    return (true);
}

void RPN::printStack() const {
    std::stack<float> copy = stack_;

    std::cout << "Elements from back to front:\n";
    while (!copy.empty()) {
        std::cout << copy.top() << " ";
        copy.pop();
    }
    std::cout << std::endl;
}

void RPN::getResult() const {
    if (stack_.size() == 1)
        std::cout << stack_.top() << std::endl;
    else
        std::cout << "Error: Need to have 1 entry only to show result, but have " << stack_.size() << std::endl;
}
