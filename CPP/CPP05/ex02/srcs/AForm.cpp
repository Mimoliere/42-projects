/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:03:15 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/17 17:03:15 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

AForm::AForm(const std::string name, const int signGrade, const int execGrade) :
	_name(name),
	_signed(0),
	_grade_to_sign(check_grade(signGrade)),
	_grade_to_exec(check_grade(execGrade))
{
	std::cout << "Form " << _name << " initiated." << std::endl;
	std::cout << "Required grade to sign : " << _grade_to_sign << std::endl;
	std::cout << "Required grade to execute : " << _grade_to_exec << std::endl;
}

AForm::AForm(const AForm& other) :
	_name(other._name),
	_signed(other._signed),
	_grade_to_sign(other._grade_to_sign),
	_grade_to_exec(other._grade_to_exec)
{
	std::cout << "AForm copy constructor called." << std::endl;
}

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other) {
		_signed = other.get_signed();
	}

	return (*this);
}

AForm::~AForm() {

}

const std::string	AForm::get_name() const {
	return (_name);
}

bool	AForm::get_signed() const {
	return (_signed);
}

int	AForm::get_grade_to_sign() const {
	return (_grade_to_sign);
}

int	AForm::get_grade_to_exec() const {
	return (_grade_to_exec);
}

void	AForm::beSigned(const Bureaucrat& brc) {
	if (brc.get_grade() > _grade_to_sign)
		throw GradeTooLowException();

	_signed = 1;
}

void	AForm::pre_execute(int const grade) const {
	if (_signed == 0)
		throw NotSignedException();
	if (grade > _grade_to_exec)
		throw NotEnoughGradeToExec();
}

int	AForm::check_grade(const int grade) {
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();

	return (grade);
}

std::ostream&	operator<<(std::ostream& os, const AForm& form) {
	os << form.get_name() << " form is " << (form.get_signed() ? "signed." : "not signed.") << std::endl;
	os << "Minimum grade to sign it : " << form.get_grade_to_sign() << std::endl;
	os << "Minimum grade to execute it : " << form.get_grade_to_exec() << std::endl;

	return (os);
}
