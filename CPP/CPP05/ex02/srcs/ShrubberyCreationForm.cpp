/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:02:57 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/17 17:02:57 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("Shrubbery Creation", 145, 137), _target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
	AForm(other), _target(other._target)
{

}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other.get_target();
	}

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	AForm::pre_execute(executor.get_grade());

	std::string		filename = _target + "_shrubbery";
	std::ofstream	outfile(filename.c_str());

	outfile << TREE;

	std::cout << executor.get_name() << " drew a splendid tree !" << std::endl;

	outfile.close();
}

std::string	ShrubberyCreationForm::get_target() const {
	return (_target);
}

void	ShrubberyCreationForm::set_target(std::string t) {
	_target = t;
}
