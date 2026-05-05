/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:53:09 by bguerrou          #+#    #+#             */
/*   Updated: 2026/05/05 10:51:41 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

// int	main(void) {
// 	// Constructeur vide
// 	Array<int>	empty;
// 	std::cout << "empty size: " << empty.size() << std::endl;

// 	// Constructeur avec n
// 	Array<int>	a(5);
// 	std::cout << "a size: " << a.size() << std::endl;
// 	for (unsigned int i = 0; i < a.size(); i++) {
// 		a[i] = i * 10;
// 		std::cout << "a[" << i << "] = " << a[i] << std::endl;
// 	}
	
// 	// Copie profonde
// 	Array<int>	b(a);
// 	b[0] = 999;
// 	std::cout << "a[0] apres modif de b: " << a[0] << std::endl;
// 	std::cout << "b[0]: " << b[0] << std::endl;

// 	// Out of bounds
// 	try {
// 		std::cout << a[99] << std::endl;
// 	} catch (std::exception& e) {
// 		std::cout << "Exception: " << e.what() << std::endl;
// 	}

// 	return 0;
// }
