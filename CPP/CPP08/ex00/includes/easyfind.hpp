/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:16:46 by bguerrou          #+#    #+#             */
/*   Updated: 2026/05/25 21:05:36 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

class NotFoundException : public std::exception {
	public:
		virtual const char*	what() const throw() {
			return ("Element not in container.");
		}
};

template <typename T>
typename T::iterator	easyfind(T& container, int to_find)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), to_find);

	if (it == container.end())
		throw NotFoundException();

	return (it);
}

#endif
