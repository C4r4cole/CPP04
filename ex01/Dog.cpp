/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:14:56 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/05 12:05:43 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	this->_brain = new Brain();
	std::cout	<< "An dog is born"
				<< std::endl;
}

Dog::Dog(const Dog &copy)
{
	this->_type = copy._type;
	this->_brain = new Brain();
	*(this->_brain) = *(copy._brain);
	std::cout	<< "Such as Dolly, a dog has been cloned"
				<< std::endl;
}

Dog &Dog::operator =(const Dog &src)
{
	if (this != &src)
	{
		this->_type = src._type;
		*(this->_brain) = *(src._brain);
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	this->_brain = 0;
	std::cout	<< "A dog is dead"
				<< std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "A dog barked" << std::endl;
}