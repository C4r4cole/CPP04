/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:22:21 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/12 16:49:38 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
	
// 	ICharacter* me = new Character("me");
	
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
	
// 	ICharacter* bob = new Character("bob");
	
// 	me->use(0, *bob);
// 	me->use(1, *bob);
	
// 	delete bob;
// 	delete me;
// 	delete src;
	
// 	return 0;
// }

int	main(void)
{
	// ***********************
	// BASIC TESTS
	// ***********************

	std::cout << std::endl;
	std::cout << RED << "*** BASIC TESTS ***" << RESET << std::endl;
	std::cout << std::endl;
	
	IMateriaSource*	src = new MateriaSource();
	
	for (int i = 0; i < 3; i++)
		std::cout << std::endl;
		
	Ice* spellA = new Ice();
	Cure* spellB = new Cure();
	
	for (int i = 0; i < 3; i++)
		std::cout << std::endl;
	
	src->learnMateria(spellA);
	src->learnMateria(spellB);

	for (int i = 0; i < 3; i++)
		std::cout << std::endl;
	
	ICharacter* caracole = new Character("caracole");
	ICharacter* sov = new Character("sov");

	for (int i = 0; i < 3; i++)
		std::cout << std::endl;
	
	AMateria* tmp = src->createMateria("ice");
	caracole->equip(tmp);
	caracole->use(0, *sov);

	for (int i = 0; i < 3; i++)
		std::cout << std::endl;
	
	tmp = src->createMateria("cure");
	caracole->equip(tmp);
	caracole->use(1, *sov);

	for (int i = 0; i < 3; i++)
		std::cout << std::endl;
	
	// ************************
	// OVERLOAD INVENTORY TESTS
	// ************************
		
	std::cout << std::endl;
	std::cout << RED << "*** OVERLOAD INVENTORY TESTS ***" << RESET << std::endl;
	std::cout << std::endl;
	
	src->printMateriaSource();
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		caracole->unequip(i);
	}
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
	{
		tmp = src->createMateria("ice");
		caracole->equip(tmp);
	}
	std::cout << std::endl;

	caracole->use(42, *sov);
	caracole->unequip(-1);
	
	for (int i = 0; i < 3; i++)
		std::cout << std::endl;

	// ************************
	// UNKNOWN TYPE
	// ************************

	std::cout << std::endl;
	std::cout << RED << "*** UNKOWN TYPE ***" << RESET << std::endl;
	std::cout << std::endl;
		
	AMateria* x = src->createMateria("fire");
	
	std::cout << x << std::endl;
	
	for (int i = 0; i < 3; i++)
		std::cout << std::endl;
	
	// *****************************************
	// UNEQUIP DOESN'T DELETE + FLOOR MANAGEMENT
	// *****************************************
	
	std::cout << std::endl;
	std::cout << RED << "*** UNEQUIP DOESN'T DELETE + FLOOR MANAGEMENT ***" << RESET << std::endl;
	std::cout << std::endl;
	
	AMateria* y = src->createMateria("cure");
	
	sov->equip(y);
	sov->use(0, *caracole);
	sov->unequip(0);
	sov->use(0, *caracole);
	
	for (int i = 0; i < 3; i++)
		std::cout << std::endl;
		
	// ************************
	// DELETE
	// ************************
	
	std::cout << std::endl;
	std::cout << RED << "*** DELETE ***" << RESET << std::endl;
	std::cout << std::endl;
	
	delete tmp;
	
	delete sov;
	delete caracole;
	
	for (int i = 0; i < 3; i++)
		std::cout << std::endl;
		
	delete src;

	for (int i = 0; i < 3; i++)
		std::cout << std::endl;
		
	delete spellA;
	delete spellB;
	
	return 0;
	}
	