/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:29:13 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/05 23:19:18 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "The ice materia has been created!" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria("ice")
{
	(void)copy;
	std::cout << "The materia has been copied" << std::endl;
}

Ice &Ice::operator =(const Ice &src)
{
	(void)src;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "The materia has been destroyed!" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria *clone = new Ice();
	return (clone);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}