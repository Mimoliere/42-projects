/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:17:13 by bguerrou          #+#    #+#             */
/*   Updated: 2026/06/04 14:23:08 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <iostream>

#include "../includes/easyfind.hpp"

int	main(void)
{
	std::vector<int>			vec = {1, 2, 3, 4};

	try {
		std::vector<int>::iterator	it = easyfind(vec, 3);

		std::cout << "Trouvé : " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator	it = easyfind(vec, 0);

		std::cout << "Trouvé : " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::list<int>	lst = {10, 20, 30};
	try {
		std::list<int>::iterator	it = easyfind(lst, 20);
		std::cout << "Trouvé dans list : " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
