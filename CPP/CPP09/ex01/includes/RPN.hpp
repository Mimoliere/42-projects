/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:05:07 by bguerrou          #+#    #+#             */
/*   Updated: 2026/06/22 16:48:26 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
	private:
		std::string		exp_;
		std::stack<int>	stck_;

		void			calcOperation(char c);

	public:
		RPN(std::string exp);
		~RPN();
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);

		void	printRes();

		class InvalidExpressionException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Error: Expression is not valid!");
				}
		};

};

#endif
