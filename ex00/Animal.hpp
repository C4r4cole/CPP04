/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:35:35 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/04 17:36:07 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class Animal
{
protected:
	std::string	_type;
public:
	Animal();
	Animal(const Animal &copy);
	Animal &operator =(const Animal &src);
	~Animal();
	
	std::string	getType() const;
	virtual void	makeSound() const;
};

#endif