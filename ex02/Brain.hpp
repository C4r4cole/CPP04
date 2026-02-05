/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:20:20 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/05 13:53:26 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class Brain
{
private:
	std::string	_ideas[100];
public:
	Brain();
	Brain(const Brain &copy);
	Brain	&operator =(const Brain &src);
	~Brain();
};

#endif