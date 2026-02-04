/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:14:10 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/04 17:38:03 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout	<< "A wrong cat is born"
				<< std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	*this = copy;
	std::cout	<< "Such as Dolly, a wrong cat has been cloned"
				<< std::endl;
}

WrongCat &WrongCat::operator =(const WrongCat &src)
{
	if (this != &src)
		this->_type = src._type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout	<< "A wrong cat is dead"
				<< std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "A wrong cat meowed" << std::endl;
}
