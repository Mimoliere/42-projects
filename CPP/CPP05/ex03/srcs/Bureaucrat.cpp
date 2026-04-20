/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:03:10 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/17 17:03:10 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();

	_grade = grade;

	std::cout << "Bureaucrat " << _name << " of grade " << _grade << " initiated." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other.get_grade()) {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other.get_grade();
	}

	return (*this);
}

Bureaucrat::~Bureaucrat() {

}

const std::string	Bureaucrat::get_name() const {
	return (_name);
}

int	Bureaucrat::get_grade() const {
	return (_grade);
}

void	Bureaucrat::set_grade(int new_grade) {
	if (new_grade < MAX_GRADE)
		throw GradeTooHighException();
	if (new_grade > MIN_GRADE)
		throw GradeTooLowException();

	_grade = new_grade;
}

void	Bureaucrat::incr_grade() {
	if (_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();

	_grade--;
}

void	Bureaucrat::decr_grade() {
	if (_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();

	_grade++;
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.get_name() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << _name << " couldn't sign the " << form.get_name() << " Form because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.get_name() << '.' << std::endl;
	} catch (const std::exception& e) {
		std::cerr << _name << " couldn't execute the " << form.get_name() << " Form because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.get_name() << ", bureaucrat grade " << bureaucrat.get_grade() << "." << std::endl;
	return (os);
}
