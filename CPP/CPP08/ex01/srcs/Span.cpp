/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:25:09 by bguerrou          #+#    #+#             */
/*   Updated: 2026/06/04 16:21:45 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span(unsigned int N) : N_(N)
{
	vec_.reserve(N_);
}

Span::Span(const Span& other) : N_(other.N_), vec_(other.vec_)
{

}

Span&	Span::operator=(const Span& other)
{
	if (this != &other) {
		N_ = other.N_;
		vec_ = other.vec_;
	}

	return (*this);
}

Span::~Span()
{

}

void	Span::addNumber(int num)
{
	if (vec_.size() == N_)
		throw AlreadyFullException();

	vec_.push_back(num);
}

void	Span::addRange(std::vector<int>::iterator begin,
						std::vector<int>::iterator end)
{
	if (vec_.size() + static_cast<std::size_t>(std::distance(begin, end)) > N_)
		throw AlreadyFullException();

	vec_.insert(vec_.end(), begin, end);
}

unsigned int	Span::shortestSpan() const
{
	if (vec_.size() < 2)
		throw NoSpanException();

	std::vector<int>::const_iterator	it;
	std::vector<int>					sortedCopy(vec_);
	unsigned int						res;

	std::sort(sortedCopy.begin(), sortedCopy.end());
	res = sortedCopy[1] - sortedCopy[0];

	for (it = sortedCopy.begin() + 2; it != sortedCopy.end(); ++it) {
		res = std::min(res, static_cast<unsigned int>(*it - *(it - 1)));
	}

	return (res);
}

unsigned int	Span::longestSpan() const
{
	if (vec_.size() < 2)
		throw NoSpanException();

	long long	minVal = *std::min_element(vec_.begin(), vec_.end());
	long long	maxVal = *std::max_element(vec_.begin(), vec_.end());

	return (static_cast<unsigned int>(maxVal - minVal));
}

std::string	Span::toString() const
{
	std::ostringstream					oss;
	std::vector<int>::const_iterator	it;

	oss << "N = " << N_ << " ; [";
	for (it = vec_.begin(); it != vec_.end(); ++it) {
		if (it != vec_.begin())
			oss << ", ";
		oss << *it;
	}
	oss << "] (" << vec_.size() << "/" << N_ << ")";
	return (oss.str());
}
