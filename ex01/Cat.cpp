/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:14:10 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/05 12:05:34 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	this->_brain = new Brain();
	std::cout	<< "A cat is born"
				<< std::endl;
}

Cat::Cat(const Cat &copy)
{
	this->_type = copy._type;
	this->_brain = new Brain();
	*(this->_brain) = *(copy._brain);
	std::cout	<< "Such as Dolly, a cat has been cloned"
				<< std::endl;
}

Cat &Cat::operator =(const Cat &src)
{
	if (this != &src)
	{
		this->_type = src._type;
		*(this->_brain) = *(src._brain);
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	this->_brain = 0;
	std::cout	<< "A cat is dead"
				<< std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "A cat meowed" << std::endl;
}
