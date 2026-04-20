/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:06:07 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/19 17:10:58 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

bool	ft_strcasecmp(const std::string& s1, const std::string& s2);

Intern::Intern() {

}

Intern::Intern(const Intern& other) {
	(void) other;
}

Intern&	Intern::operator=(const Intern& other) {
	(void) other;
	return (*this);
}

Intern::~Intern() {

}

AForm*	Intern::makeForm(const std::string form_name, const std::string target) {
	AForm*		form;
	std::string	names[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	int			i = 0;

	while (i < 3 && !ft_strcasecmp(form_name, names[i]))
		i++;

	switch (i) {
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cerr << "Intern could not create " << form_name << '.' << std::endl;
			throw UnknownFormException();
	}

	std::cout << "Intern creates " << form->get_name() << '.' << std::endl;
	return (form);
}

bool	ft_strcasecmp(const std::string& s1, const std::string& s2) {
	size_t	l1 = s1.length();

	if (l1 != s2.length())
		return (false);

	for (size_t i = 0; i < l1; i++) {
		if (std::tolower(s1[i]) != std::tolower(s2[i]))
			return (false);
	}

	return (true);
}
