/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:23:30 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/06 20:23:46 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Harl {
   public:
    void complain(std::string level) const;

    Harl();
    ~Harl();

   private:
    void debug() const;
    void info() const;
    void warning() const;
    void error() const;
};

#endif /* ********************************************************** HARL_H */