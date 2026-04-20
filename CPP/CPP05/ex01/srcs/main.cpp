/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:03:33 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/17 17:03:34 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

static void print_header(const std::string& title) {
	std::cout << "\n" << BOLD << CYAN << "==== " << title << " ====" << RESET << std::endl;
}

static void print_ok(const std::string& msg) {
	std::cout << GREEN << "[OK] " << RESET << msg << std::endl;
}

static void print_fail(const std::exception& e) {
	std::cout << RED << "[EXCEPTION] " << RESET << " -> " << e.what() << std::endl;
}

int main(void) {
	print_header("Constructeur de Form : Valide");
	try {
		Form f1("Tax return", 50, 20);
		print_ok("Formulaire creé avec succès");
		std::cout << f1;
	} catch (const std::exception& e) {
		print_fail(e);
	}

	print_header("Constructeur de Form : Grade trop haut");
	try {
		Form f2("Top Secret", 0, 10);
		std::cout << f2;
		print_ok("Cette ligne ne devrait pas s'afficher");
	} catch (const std::exception& e) {
		print_fail(e);
	}

	print_header("Constructeur de Form : Grade trop bas");
	try {
		Form f3("Trash", 151, 150);
		std::cout << f3;
		print_ok("Cette ligne ne devrait pas s'afficher");
	} catch (const std::exception& e) {
		print_fail(e);
	}

	print_header("Bureaucrat signe avec succès");
	try {
		Bureaucrat b1("Alice", 40);
		Form f4("Permis A38", 50, 50);
		b1.signForm(f4);
		print_ok("Le formulaire devrait être signé");
		std::cout << f4;
	} catch (const std::exception& e) {
		print_fail(e);
	}

	print_header("Bureaucrat échoue à signer (grade insuffisant)");
	try {
		Bureaucrat b2("Bob", 60);
		Form f5("Declaration fiscale", 50, 50);
		b2.signForm(f5);
		print_ok("Le formulaire ne devrait PAS être signé");
		std::cout << f5;
	} catch (const std::exception& e) {
		print_fail(e);
	}

	return (0);
}
