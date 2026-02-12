/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:29:13 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/12 14:55:11 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "The cure materia has been created!" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria("cure")
{
	(void)copy;
	std::cout << "The materia has been copied" << std::endl;
}

Cure &Cure::operator =(const Cure &src)
{
	(void)src;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "The materia has been destroyed!" << std::endl;
}

AMateria* Cure::clone() const
{
	std::cout << YELLOW << "!Cloned! " << RESET;
	AMateria *clone = new Cure();
	return (clone);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}