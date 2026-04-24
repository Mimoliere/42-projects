/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:02:25 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/23 15:24:52 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../includes/Serializer.hpp"

int	main(void) {
	Data	d(42);

	std::cout << "Adress : " << &d << std::endl;

	uintptr_t	s = Serializer::serialize(&d);
	std::cout << "Serialization : " << s << std::endl;

	Data*	adress = Serializer::deserialize(s);
	std::cout << "Deserialization : " << adress << std::endl;

	return (0);
}
