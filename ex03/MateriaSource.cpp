/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:15:11 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/12 15:48:52 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "A MateriaSource has been created" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_templates[i] = 0;
	}
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	std::cout << "A MateriaSource has been copied" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_templates[i] = 0;
		if (copy._templates[i] != 0)
			_templates[i] = copy._templates[i]->clone();
	}
}

MateriaSource &MateriaSource::operator =(MateriaSource const &src)
{
	std::cout << "MateriaSource's Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _templates[i];
			_templates[i] = 0;
			if (src._templates[i] != 0)
				_templates[i] = src._templates[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "A MateriaSource has been destroyed" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] != 0)
		{
			delete _templates[i];
			_templates[i] = 0;
		}
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

void	MateriaSource::printMateriaSource() const
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] != 0)
			std::cout << i + 1 << " - " << _templates[i]->getType() << std::endl;
		else
			std::cout << i + 1 << " - " << BLUE << "empty" << RESET << std::endl;
	}
}
