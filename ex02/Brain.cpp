/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:27:56 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/05 13:53:19 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "A brain has been transplanted" << std::endl;
}
Brain::Brain(const Brain &copy)
{
	*this = copy;
}

Brain	&Brain::operator =(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return (*this);
}
	
Brain::~Brain()
{
	std::cout << "An electroencephalogram is flat. A Brain is dead..." << std::endl;
}
