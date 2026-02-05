/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:35:01 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/05 14:05:34 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal *animals[6];
	
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (int i = 0; i < 3; i++)
		std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		delete animals[i];

	for (int i = 0; i < 3; i++)
		std::cout << std::endl;

	Dog	a;
	Dog	b(a);

	for (int i = 0; i < 3; i++)
		std::cout << std::endl;

	std::cout << "l'adresse de a est : " << &a << std::endl;
	std::cout << "l'adresse de b est : " << &b << std::endl;

	std::cout << "l'adresse du brain de a est : " << &a.getBrain() << std::endl;
	std::cout << "l'adresse du brain de b est : " << &b.getBrain() << std::endl;

	for (int i = 0; i < 3; i++)
		std::cout << std::endl;
	
	return 0;
}