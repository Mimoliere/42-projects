/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:25:16 by bguerrou          #+#    #+#             */
/*   Updated: 2026/05/29 16:48:41 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <limits.h>

class Span {
	private:
		unsigned int		N_;
		std::vector<int>	vec_;

	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		void			addNumber(int num);
		void			addRange(std::vector<int>::iterator begin,
								std::vector<int>::iterator end);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		std::string		toString() const;

		class AlreadyFullException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("Storage is already full.");
				}
		};

		class NoSpanException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("No span can be found.");
				}
		};

};

#endif
