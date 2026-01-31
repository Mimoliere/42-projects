/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceStr.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:05:46 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:05:47 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/replaceStr.hpp"

int	replaceStr(char *argv[]) {

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string s2 = argv[3];

	if (!s1.compare(s2)) {
		std::cout << "Nothing to replace." << std::endl;
		return (1);
	}

	std::ifstream	file(argv[1]);
	if (!file.is_open()) {
		std::cout << "Error: Unable to open file !" << std::endl;
		std::cout << "Check if it exists or if you have the correct access rights" << std::endl;
		return (2);
	}

	std::ofstream	outfile(getNewName(filename).c_str());
	if (!outfile.is_open()) {
		std::cout << "Error: Unable to create file !" << std::endl;
		file.close();
		return (3);
	}

	modifiedFile(file, outfile, s1, s2);

	file.close();
	outfile.close();
	return (0);
}

void	modifiedFile(std::ifstream& file, std::ofstream& outfile, std::string s1, std::string s2) {
	std::string	buffer;
	std::string finalString;
	int			i;

	while (std::getline(file, buffer)) {
		i = buffer.find(s1);
		while (i != (int) std::string::npos) {
			buffer.erase(i, s1.length());
			buffer.insert(i, s2);
			i = buffer.find(s1);
		}
		finalString.append(buffer + "\n");
	}

	outfile << finalString;
}

std::string	getNewName(std::string filename) {
	std::string		newFileName(filename);

	newFileName.append(".replace");

	return (newFileName);
}
