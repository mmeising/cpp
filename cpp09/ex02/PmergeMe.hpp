/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:07:28 by mmeising          #+#    #+#             */
/*   Updated: 2023/04/11 01:32:00 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

// template <typename T>
// void foo()
// {
//     if (typeid(T) == typeid(animal)) { /* ... */ }
// }

class PmergeMe {
   public:
    PmergeMe();
    ~PmergeMe();

    void sortVector(char** argv);

   protected:
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& rhs);
    bool checkInput(char** argv) const;
    
   private:
    
};
