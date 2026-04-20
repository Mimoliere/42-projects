/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:03:02 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/17 17:03:02 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("Robotomy Request", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other), _target(other._target)
{

}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other.get_target();
	}

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	AForm::pre_execute(executor.get_grade());

	int	random = rand();

	std::cout << "VRIIIIIIIIIIIIIIIIIIIIIIII !!!" << std::endl;

	if (random % 2 == 0) {
		std::cout << _target << " has been robotomized successfully !" << std::endl;
	} else {
		std::cout << _target << "'s robotomy has failed..." << std::endl;
	}
}

std::string	RobotomyRequestForm::get_target() const {
	return (_target);
}

void	RobotomyRequestForm::set_target(std::string t) {
	_target = t;
}
