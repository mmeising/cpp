/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:22:18 by mmeising          #+#    #+#             */
/*   Updated: 2022/09/06 13:09:53 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
   public:
    Brain();
    Brain(Brain const& src);
    ~Brain();

    Brain& operator=(Brain const& rhs);
    std::string* getIdeas();
    std::string getIdea(int i);

    void setIdea(int i, std::string idea);

   private:
    std::string ideas_[100];
};

// std::ostream& operator<<(std::ostream& o, Brain const& i);

#endif /* ********************************************************* BRAIN_H */