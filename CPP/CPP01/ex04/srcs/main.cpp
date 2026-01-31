/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:05:43 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:05:44 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/replaceStr.hpp"

int	main(int argc, char *argv[]) {
	int	ret = 0;

	if (argc != 4) {
		std::cout << "Wrong number of arguments." << std::endl;
		std::cout << "Usage: ./sed <file_to_read> <str_to_replace> <new_str>" << std::endl;
		return (1);
	}

	std::cout << "str: " << argv[2] << std::endl;
	std::cout << "new: " << argv[3] << std::endl << std::endl;

	ret = replaceStr(argv);
	if (ret == 0)
		std::cout << "Replaced successfully !" << std::endl;
	if (ret == 1)
		ret = 0;
	return (ret);
}
