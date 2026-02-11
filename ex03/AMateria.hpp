/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:22:14 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/11 15:57:30 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <cstdlib>
# include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria(std::string const & type);
		AMateria(const AMateria &copy);
		AMateria &operator =(const AMateria &src);
		virtual ~AMateria();

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif