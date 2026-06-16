/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:25:04 by bguerrou          #+#    #+#             */
/*   Updated: 2026/06/05 13:47:48 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

#define RESET	"\033[0m"
#define BOLD	"\033[1m"
#define DIM		"\033[2m"
#define YELLOW	"\033[33m"
#define CYAN	"\033[36m"
#define GREEN	"\033[32m"

static void	section(const std::string& title)
{
	std::cout << BOLD << YELLOW << "\n=== " << title << " ===" << RESET << std::endl;
}

static void	result(const std::string& label, unsigned int value)
{
	std::cout << "  " << label << BOLD << GREEN << value << RESET
		<< DIM << RESET << std::endl;
}

int	main(void)
{
	// --- Exemple du sujet ---
	section("Exemple sujet");
	{
		Span	sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	
		std::cout << DIM << "  " << sp.toString() << RESET << std::endl;
		result("shortestSpan: ", sp.shortestSpan());
		result("longestSpan:  ", sp.longestSpan());
	}

	// --- NoSpanException ---
	section("NoSpanException");
	{
		Span	sp(3);

		try {
			sp.shortestSpan();
		} catch (std::exception& e) {
			std::cout << CYAN << " " << e.what() << RESET << std::endl;
		}
		try {
			sp.longestSpan();
		} catch (std::exception& e) {
			std::cout << CYAN << " " << e.what() << RESET << std::endl;
		}

		sp.addNumber(42);
		try {
			sp.shortestSpan();
		} catch (std::exception& e) {
			std::cout << CYAN << " " << e.what() << RESET << std::endl;
		}
	}

	// --- AlreadyFullException (addNumber) ---
	section("AlreadyFullException - addNumber");
	{
		Span	sp(2);

		sp.addNumber(1);
		sp.addNumber(2);
		try {
			sp.addNumber(3);
		} catch (std::exception& e) {
			std::cout << CYAN << " " << e.what() << RESET << std::endl;
		}
	}

	// --- addRange OK ---
	section("addRange - nominal");
	{
		Span				sp(5);
		std::vector<int>	v;

		v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4); v.push_back(5);
		sp.addRange(v.begin(), v.end());

		std::cout << DIM << "  " << sp.toString() << RESET << std::endl;
		result("shortestSpan: ", sp.shortestSpan());
		result("longestSpan:  ", sp.longestSpan());
	}

	// --- addRange depasse la capacite ---
	section("AlreadyFullException - addRange");
	{
		Span				sp(3);
		std::vector<int>	v;

		v.push_back(10); v.push_back(20); v.push_back(30); v.push_back(40);

		try {
			sp.addRange(v.begin(), v.end());
		} catch (std::exception& e) {
			std::cout << CYAN << " " << e.what() << RESET << std::endl;
		}
	}

	// --- Doublons et negatifs ---
	section("Doublons et nombres negatifs");
	{
		Span				sp1(3);
		std::vector<int>	v1;

		v1.push_back(10); v1.push_back(10); v1.push_back(20);
		sp1.addRange(v1.begin(), v1.end());
		std::cout << DIM << "  " << sp1.toString() << RESET << std::endl;
		result("doublons - shortestSpan: ", sp1.shortestSpan());
		result("doublons - longestSpan:  ", sp1.longestSpan());

		Span				sp2(4);
		std::vector<int>	v2;

		v2.push_back(-10); v2.push_back(-3); v2.push_back(0); v2.push_back(7);
		sp2.addRange(v2.begin(), v2.end());
		std::cout << DIM << "  " << sp2.toString() << RESET << std::endl;
		result("negatifs - shortestSpan: ", sp2.shortestSpan());
		result("negatifs - longestSpan:  ", sp2.longestSpan());
	}

	// --- Copie / Assignation ---
	section("Copie et assignation");
	{
		Span	original(6);

		original.addNumber(1);
		original.addNumber(5);
		original.addNumber(10);

		Span	copy(original);

		original.addNumber(100);
		std::cout << DIM << "  " << copy.toString() << RESET << std::endl;
		result("copy.shortestSpan: ", copy.shortestSpan());
		result("copy.longestSpan:  ", copy.longestSpan());

		Span	assigned(1);

		assigned = original;
		std::cout << DIM << "  " << assigned.toString() << RESET << std::endl;
		result("assigned.shortestSpan: ", assigned.shortestSpan());
		result("assigned.longestSpan:  ", assigned.longestSpan());
	}

	// --- Valeurs extremes ---
	section("Valeurs extremes INT_MIN / INT_MAX");
	{
		Span				sp(3);
		std::vector<int>	v;

		v.push_back(INT_MIN); v.push_back(0); v.push_back(INT_MAX);
		sp.addRange(v.begin(), v.end());
		std::cout << DIM << "  " << sp.toString() << RESET << std::endl;
		result("shortestSpan: ", sp.shortestSpan());
		result("longestSpan:  ", sp.longestSpan());
	}

	// --- Gros dataset ---
	section("Gros dataset (10000 elements)");
	{
		const unsigned int	N = 10000;
		Span				sp(N);
		std::vector<int>	v;

		v.reserve(N);
		std::srand(42);
		for (unsigned int i = 0; i < N; ++i)
			v.push_back(std::rand());
		sp.addRange(v.begin(), v.end());

		std::cout << "  shortestSpan: " << BOLD << GREEN << sp.shortestSpan() << RESET << std::endl;
		std::cout << "  longestSpan:  " << BOLD << GREEN << sp.longestSpan()  << RESET << std::endl;
	}

	return (0);
}