/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:55:42 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/11 16:30:09 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include <string>
# include "AMateria.hpp"

class AMateria;

class MateriaSource
{
	private:
		AMateria*	_templates[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &copy);
		MateriaSource &operator =(MateriaSource const &src);
		virtual ~MateriaSource() {}
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};

#endif