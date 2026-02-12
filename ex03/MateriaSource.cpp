/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:15:11 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/12 11:12:59 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		_templates[i] = 0;
	}
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	for (int i = 0; i < 4; i++)
	{
		_templates[i] = 0;
	}
}

MateriaSource &MateriaSource::operator =(MateriaSource const &src)
{
	for (int i = 0; i < 4; i++)
	{
		_templates[i] = 0;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] != 0)
			delete _templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == 0)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] == 0)
		{
			_templates[i] = m->clone();
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] == 0)
			continue ;
		if (_templates[i]->getType() == type)
			return (_templates[i]->clone());
	}
	return 0;
}
