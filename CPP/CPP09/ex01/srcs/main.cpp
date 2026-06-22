/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:05:09 by bguerrou          #+#    #+#             */
/*   Updated: 2026/06/22 16:52:22 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2) {
		std::cerr << "Error: Wrong number of arguments." << std::endl << "Usage: \' ./RPN \"1 2 +\" \'" << std::endl;
		return (1);
	}

	try {
		RPN	rpn(argv[1]);
		rpn.printRes();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
