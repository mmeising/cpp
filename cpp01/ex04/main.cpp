/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:41:12 by mmeising          #+#    #+#             */
/*   Updated: 2022/07/05 19:47:49 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceFile.hpp"

int main(int argc, char **argv) {
    ReplaceFile rep;

    if (rep.setValues(argc, argv)) { return 1; }
    if (rep.readFromFile()) { return 2; }
    rep.replaceStrings();
    if (rep.writeToFile()) { return 3; }
    return 0;
}
