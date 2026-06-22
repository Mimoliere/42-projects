/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:53:56 by bguerrou          #+#    #+#             */
/*   Updated: 2026/06/22 16:56:55 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cerr << "Error: Wrong number of arguments." << std::endl
					<< "Usage: ./PmergeMe 1 2 3 ..." << std::endl;
	}

	return (0);
}
