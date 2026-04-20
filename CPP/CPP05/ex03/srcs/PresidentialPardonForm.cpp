/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:03:04 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/17 17:03:05 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
    AForm("Presidential Pardon", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
    AForm(other), _target(other._target)
{

}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other.get_target();
    }

    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    AForm::pre_execute(executor.get_grade());

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string	PresidentialPardonForm::get_target() const {
	return (_target);
}

void	PresidentialPardonForm::set_target(std::string t) {
	_target = t;
}
