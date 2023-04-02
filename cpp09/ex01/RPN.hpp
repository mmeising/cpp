/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:14:45 by mmeising          #+#    #+#             */
/*   Updated: 2023/04/02 21:58:54 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
 
class RPN {
   public:
    RPN();
    RPN(RPN const& src);
    ~RPN();

    bool input(std::string input);

    void getResult() const;

    RPN& operator=(RPN const& rhs);

   private:
    std::stack<float> stack_;

    bool calc(std::string input);
    void printStack() const;        //just used for debugging
};
