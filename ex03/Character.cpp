/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 23:50:31 by fmoulin           #+#    #+#             */
/*   Updated: 2026/02/05 23:50:41 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

virtual ~ICharacter() {}
virtual std::string const & getName();
virtual void equip(AMateria* m);
virtual void unequip(int idx);
virtual void use(int idx, ICharacter& target);