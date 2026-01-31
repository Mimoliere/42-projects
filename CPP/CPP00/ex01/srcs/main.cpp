/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:02:00 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:02:00 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.hpp"
#include "../includes/PhoneBook.hpp"

int main(void) {
	std::string	answer;
	PhoneBook	phonebook;

	std::cout << "Welcome to your Phonebook !" << std::endl;
	while (phonebook.getStop())
	{
		std::cout << "What do you want to do ? (ADD / SEARCH / EXIT)" << std::endl << "- ";
		if (!getline(std::cin, answer))
			phonebook.setStop(false);
		if (!answer.compare("ADD"))
			phonebook.addContact();
		if (!answer.compare("SEARCH"))
			phonebook.searchContact();
		if (!answer.compare("EXIT"))
			phonebook.setStop(false);
	}
	std::cout << "Goodbye !" << std::endl;
}
