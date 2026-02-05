/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:39:34 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/05 14:48:03 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout	<< "An animal is born"
				<< std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout	<< "Such as Dolly, an animal has been cloned"
				<< std::endl;
}

Animal &Animal::operator =(const Animal &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}


Animal::~Animal()
{
	std::cout	<< "An animal is dead"
				<< std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

