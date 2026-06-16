/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:51:28 by bguerrou          #+#    #+#             */
/*   Updated: 2026/06/16 23:20:31 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>

#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);

	// --- const_iterator : on doit pouvoir parcourir un MutantStack const ---
	std::cout << "--- const_iterator ---" << std::endl;
	const MutantStack<int>	cstack(mstack);

	for (MutantStack<int>::const_iterator cit = cstack.begin(); cit != cstack.end(); ++cit)
		std::cout << *cit << std::endl;

	// --- reverse_iterator : parcours du dernier au premier ---
	std::cout << "--- reverse_iterator ---" << std::endl;
	for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
		std::cout << *rit << std::endl;

	// --- equivalence avec std::list : memes operations => meme sortie ---
	std::cout << "--- std::list (reference) ---" << std::endl;
	std::list<int>	l;

	l.push_back(5);
	l.push_back(17);
	std::cout << l.back() << std::endl;
	l.pop_back();
	std::cout << l.size() << std::endl;
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(0);
	for (std::list<int>::iterator lit = l.begin(); lit != l.end(); ++lit)
		std::cout << *lit << std::endl;

	// --- conteneur sous-jacent different : std::vector au lieu de deque ---
	std::cout << "--- MutantStack<int, std::vector<int> > ---" << std::endl;
	MutantStack<int, std::vector<int> >	vstack;

	vstack.push(42);
	vstack.push(21);
	vstack.push(84);
	for (MutantStack<int, std::vector<int> >::iterator vit = vstack.begin(); vit != vstack.end(); ++vit)
		std::cout << *vit << std::endl;

	return (0);
}
