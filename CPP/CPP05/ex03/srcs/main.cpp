/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:02:29 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/19 17:13:08 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

static void print_title(std::string title) {
	std::cout << "\n" << BOLD << CYAN << "=== " << title << " ===" << RESET << std::endl;
}

int main(void) {
	srand(time(NULL));

	Intern someRandomIntern;
	AForm* rrf;
	AForm* ppf;
	AForm* scf;
	AForm* unknown;

	print_title("1. Creating a Robotomy Request Form (from subject)");
	std::cout << YELLOW;
	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf) {
			std::cout << GREEN << "Created: " << rrf->get_name() << RESET << std::endl;
			delete rrf;
		}
	} catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	print_title("2. Creating a Presidential Pardon Form");
	std::cout << YELLOW;
	try {
		ppf = someRandomIntern.makeForm("Presidential PARDON", "Zaphod");
		if (ppf) {
			std::cout << GREEN << "Created: " << ppf->get_name() << RESET << std::endl;
			delete ppf;
		}
	} catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	print_title("3. Creating a Shrubbery Creation Form");
	std::cout << YELLOW;
	try {
		scf = someRandomIntern.makeForm("Shrubbery Creation", "Home");
		if (scf) {
			std::cout << GREEN << "Created: " << scf->get_name() << RESET << std::endl;
			delete scf;
		}
	} catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	print_title("4. Creating an Unknown Form");
	std::cout << YELLOW;
	try {
		unknown = someRandomIntern.makeForm("random form that doesnt exist", "Nobody");
		if (unknown) {
			std::cout << GREEN << "Created: " << unknown->get_name() << RESET << std::endl;
			delete unknown;
		}
	} catch (std::exception &e) {
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	return (0);
}
