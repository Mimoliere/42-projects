/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:10:35 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:10:37 by bguerrou         ###   ########.fr       */
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
