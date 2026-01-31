/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:35 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:11:35 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other.getIdeas(i);
	}
}

Brain&	Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other.getIdeas(i);
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

std::string	Brain::getIdeas(int index) const {
	return (_ideas[index]);
}

void	Brain::setIdeas(int index, std::string newVal) {
	_ideas[index] = newVal;
}
