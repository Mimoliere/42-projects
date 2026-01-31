/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:18 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:11:20 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

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
