/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:50:31 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/11 15:52:32 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _floorIdx(0)
{
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
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m)
			return ;
		if (_inventory[i] == 0)
		{
			_inventory[i] = m;
			return ;
		}
	}
	return ;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (_inventory[idx] == 0)
		return ;
	if (_floorIdx < 100)
	{
		this->_floor[_floorIdx] = _inventory[idx];
		_floorIdx++;
	}
	_inventory[idx] = 0;
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
		return ;
	if (_inventory[idx] == 0)
		return ;
	_inventory[idx]->use(target);
}
