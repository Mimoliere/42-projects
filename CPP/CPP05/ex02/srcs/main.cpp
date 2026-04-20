/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:02:29 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/17 17:03:07 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../includes/Bureaucrat.hpp"
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

	print_title("1. Création des Bureaucrates");
	std::cout << YELLOW;
	Bureaucrat boss("Boss", 1);
	Bureaucrat manager("Manager", 50);
	Bureaucrat intern("Intern", 140);
	Bureaucrat pleb("Pleb", 150);

	std::cout << boss << manager << intern << pleb;

	print_title("2. ShrubberyCreationForm (Sign 145, Exec 137)");
	std::cout << YELLOW;
	ShrubberyCreationForm shrub("home");
	std::cout << RED;
	// Échec : Formulaire non signé
	boss.executeForm(shrub);
	// Échec : Grade trop bas pour signer
	pleb.signForm(shrub);
	// Succès : Signature
	std::cout << GREEN;
	intern.signForm(shrub);
	// Échec : Grade trop bas pour exécuter
	std::cout << RED;
	intern.executeForm(shrub);
	// Succès : Exécution (Génère le fichier)
	std::cout << GREEN;
	manager.executeForm(shrub);

	print_title("3. RobotomyRequestForm (Sign 72, Exec 45)");
	std::cout << YELLOW;
	RobotomyRequestForm robot("Claptrap");
	// Échec : Grade trop bas pour signer
	std::cout << RED;
	intern.signForm(robot);
	// Succès : Signature
	std::cout << GREEN;
	manager.signForm(robot);
	// Échec : Grade trop bas pour exécuter
	std::cout << RED;
	manager.executeForm(robot);
	// Succès : Exécutions multiples pour tester les 50% de chance
	std::cout << GREEN;
	boss.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);

	print_title("4. PresidentialPardonForm (Sign 25, Exec 5)");
	std::cout << YELLOW;
	PresidentialPardonForm pardon("Arthur Dent");
	// Échec : Grade trop bas pour signer
	std::cout << RED;
	manager.signForm(pardon);
	// Succès : Signature
	std::cout << GREEN;
	boss.signForm(pardon);
	// Échec : L'intern tente d'exécuter un formulaire présidentiel signé 
	std::cout << RED;
	intern.executeForm(pardon);
	// Succès : Exécution
	std::cout << GREEN;
	boss.executeForm(pardon);

	return (0);
}
