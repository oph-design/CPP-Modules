/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:55:00 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/14 15:29:19 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string newName)
	: _name(newName)
{

}

Zombie::~Zombie(void)
{
	std::cout << _name << " rotted away" << std::endl;
}

std::string Zombie::getName(void) const
{
	return (_name);
}

void Zombie::setName(std::string newName)
{
	_name = newName;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
