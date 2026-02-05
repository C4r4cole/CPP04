/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:39:34 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/04 17:37:49 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout	<< "An wrong animal is born"
				<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
	std::cout	<< "Such as Dolly, a wrong animal has been cloned"
				<< std::endl;
}

WrongAnimal &WrongAnimal::operator =(const WrongAnimal &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}


WrongAnimal::~WrongAnimal()
{
	std::cout	<< "A wrong animal is dead"
				<< std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "A wrong animal whispered..." << std::endl;
}
