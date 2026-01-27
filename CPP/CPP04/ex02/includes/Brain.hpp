#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#pragma once

class Brain {

	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		~Brain();

		std::string	getIdeas(int index) const;
		void	setIdeas(int index, std::string newVal);

};

#endif
