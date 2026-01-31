/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:43 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:11:43 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

#define NBR 4

int main()
{
	Dog		dog;
	Cat*	cat = new Cat();

	dog.makeSound();
	cat->makeSound();

	delete cat;

	return (0);
}
