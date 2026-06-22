/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 16:05:12 by bguerrou          #+#    #+#             */
/*   Updated: 2026/06/22 16:48:41 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN(std::string exp) : exp_(exp)
{
	size_t	numOnly = exp_.find_first_not_of("0123456789 +-/*");
	size_t	i = 0;

	if (numOnly != std::string::npos)
		throw InvalidExpressionException();

	while (i < exp_.size()) {
		while (i < exp_.size() && exp_[i] == ' ')
			i++;

		if (i < exp_.size() && exp_[i] >= '0' && exp_[i] <= '9') {
			stck_.push(exp_[i] - '0');
		}
		else if (i < exp_.size()) {
			if (stck_.size() < 2)
				throw InvalidExpressionException();
			calcOperation(exp_[i]);
		}

		if (++i < exp_.size() && exp_[i] != ' ')
			throw InvalidExpressionException();
	}

	if (stck_.size() != 1)
		throw InvalidExpressionException();
}

RPN::~RPN()
{
	
}

RPN::RPN(const RPN& other)
{
	exp_ = other.exp_;
	stck_ = other.stck_;
}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other) {
		exp_ = other.exp_;
		stck_ = other.stck_;
	}

	return (*this);
}

void	RPN::calcOperation(char c)
{
	int	n1 = stck_.top();	stck_.pop();
	int	n2 = stck_.top();	stck_.pop();

	if (c == '+')
		stck_.push(n1 + n2);
	if (c == '-')
		stck_.push(n2 - n1);
	if (c == '/') {
		if (n1 == 0)
			throw InvalidExpressionException();
		stck_.push(n2 / n1);
	}
	if (c == '*')
		stck_.push(n1 * n2);
}

void	RPN::printRes()
{
	std::cout << stck_.top() << std::endl;
}
