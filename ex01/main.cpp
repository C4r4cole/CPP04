/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:35:01 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/04 18:06:22 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	for (int i = 0; i < 5; i++)
		std::cout << std::endl;

	const WrongAnimal* h = new WrongCat();
	std::cout << h->getType() << " " << std::endl;
	h->makeSound();

	for (int i = 0; i < 5; i++)
		std::cout << std::endl;
	
	delete h;
	delete j;
	delete i;
	return 0;
}