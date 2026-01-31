/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:01:05 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:01:05 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int	main(int argc, char **argv) {
	std::string	arg;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			arg = argv[i];
			for (int j = 0; arg[j]; j++) {
				arg[j] = std::toupper(static_cast<unsigned char>(arg[j]));
			}
			std::cout << arg;
		}
	}
	std::cout << std::endl;
	return (0);
}
