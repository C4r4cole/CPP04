/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:22:18 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/11 14:52:02 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "The materia has been created!" << std::endl;
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
	std::cout << "The materia has been copied" << std::endl;
}

AMateria &AMateria::operator =(const AMateria &src)
{
	(void)src;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "The materia has been destroyed!" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}