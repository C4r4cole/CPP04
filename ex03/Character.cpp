/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:50:31 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/12 16:44:37 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _floorIdx(0)
{
	std::cout << "The character " << _name << " is born in Aberlaas" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = 0;
	}
	for (int i = 0; i < 100; i++)
	{
		_floor[i] = 0;
	}
}

Character::Character(const Character &copy) : _name(copy._name), _floorIdx(0)
{
	std::cout << "The character " << _name << " has been cloned in Norska" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = 0;
		if (copy._inventory[i] != 0)
			this->_inventory[i] = copy._inventory[i]->clone();
	}
	for (int i = 0; i < 100; i++)
		this->_floor[i] = 0;
}

Character &Character::operator =(const Character &src)
{
	std::cout << "Character's Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			this->_inventory[i] = 0;
			if (src._inventory[i] != 0)
				this->_inventory[i] = src._inventory[i]->clone();
		}
		for (int i = 0; i < 100; i++)
		{
			delete _floor[i];
			this->_floor[i] = 0;
		}
		this->_floorIdx = 0;
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "The character " << _name << " is dead in Lapsane's pond" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		_inventory[i] = 0;
	}
	for (int i = 0; i < 100; i++)
	{
		delete _floor[i];
		_floor[i] = 0;
	}
}


std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (m == 0)
		return ;
	for (int i = 0; i < 5; i++)
	{
		if (i == 4)
		{
			std::cout << MAGENTA << "Inventory is full! Nothing has been done..." << RESET << std::endl;
			return ;
		}
		if (_inventory[i] == m)
			return ;
		if (_inventory[i] == 0)
		{
			_inventory[i] = m;
			std::cout << "The materia " << m->getType() << " has been equiped" << std::endl;
			return ;
		}
	}
	return ;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << MAGENTA << "Nothing has been done..." << RESET << std::endl;
		return ;
	}
	if (_inventory[idx] == 0)
	{
		std::cout << MAGENTA << "Nothing has been done..." << RESET << std::endl;
		return ;
	}
	if (_floorIdx < 100)
	{
		this->_floor[_floorIdx] = _inventory[idx];
		std::cout << this->_inventory[idx]->getType() << " has been unequiped" << std::endl;
		_floorIdx++;
	}
	_inventory[idx] = 0;
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << MAGENTA << "Nothing has been done..." << RESET << std::endl;
		return ;
	}
	if (_inventory[idx] == 0)
	{
		std::cout << MAGENTA << "Nothing has been done..." << RESET << std::endl;
		return ;
	}
	std::cout << _name << " ";
	_inventory[idx]->use(target);
}
