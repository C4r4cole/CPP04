/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:22:14 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/12 15:54:41 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <cstdlib>
# include <iostream>

#define RED     "\033[1;4;31m"
#define GREEN   "\033[1;4;32m"
#define YELLOW  "\033[1;4;33m"
#define BLUE    "\033[1;4;34m"
#define MAGENTA "\033[1;4;35m"
#define CYAN    "\033[1;4;36m"
#define RESET   "\033[0m"

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