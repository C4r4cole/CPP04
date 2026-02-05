/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:14:10 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/04 17:38:03 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout	<< "A cat is born"
				<< std::endl;
}

Cat::Cat(const Cat &copy)
{
	*this = copy;
	std::cout	<< "Such as Dolly, a cat has been cloned"
				<< std::endl;
}

Cat &Cat::operator =(const Cat &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout	<< "A cat is dead"
				<< std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "A cat meowed" << std::endl;
}
