/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:06:34 by mmeising          #+#    #+#             */
/*   Updated: 2022/12/09 19:28:24 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/**
 * A X		rock		1
 * B Y		paper		2
 * C Z		scissors	3
 * 
 * lose					0
 * draw					3
 * win					6
*/

std::string	read_file(std::string filename)
{
	std::string	ret;

	std::ifstream	inputFile(filename);
	if (!inputFile.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return (ret);
	}
	std::string	line;
	while (getline(inputFile, line)) {
		ret += line;
		// std::cout << line << std::endl;
	}
	inputFile.close();
	return (ret);
}

int	calc_line(std::string& input) {
	std::string	line = input.substr(0, 3);
	int			score = 0;
	static int line_count;

	// if (!line.compare("A X") || !line.compare("B Y") || !line.compare("C Z"))
	// 	score += 3;
	// else if (!line.compare("A Y") || !line.compare("B Z") || !line.compare("C X"))
	// 	score += 6;
	
	// if (line.find('X') != std::string::npos)
	// 	score += 1;
	// else if (line.find('Y') != std::string::npos)
	// 	score += 2;
	// else if (line.find('Z') != std::string::npos)
	// 	score += 3;

	if (!line.compare("A X"))
		score += 3;//scissors, loss
	else if (!line.compare("B X"))
		score += 1;//rock loss
	else if (!line.compare("C X"))
		score += 2;//paper, loss
	else if (!line.compare("A Y"))
		score += 4;
	else if (!line.compare("B Y"))
		score += 5;
	else if (!line.compare("C Y"))
		score += 6;
	else if (!line.compare("A Z"))
		score += 8;
	else if (!line.compare("B Z"))
		score += 9;
	else if (!line.compare("C Z"))
		score += 7;

	input.erase(0, 3);
	line_count++;
	// if (line_count > 10)
	// 	exit(1);
	std::cout << line_count << " line |" << line << "|score is " << score << std::endl;
	return (score);
}

void	calc_score(std::string& input) {
	int	total = 0;
	while (input.size()) {
		total += calc_line(input);
	}
	std::cout << "total count is " << total << std::endl;
}

int main(void) {
	std::string	input = read_file("02.txt");
	
	calc_score(input);
}