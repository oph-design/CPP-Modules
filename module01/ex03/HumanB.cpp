/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:47:21 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/14 15:27:00 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
	: _name(newName), _weapon(NULL)
{

}

HumanB::~HumanB(void)
{

}

std::string HumanB::getName(void) const
{
	return (_name);
}

Weapon HumanB::getWeapon(void) const
{
	return (*_weapon);
}

void HumanB::setName(std::string newName)
{
	_name = newName;
}
void HumanB::setWeapon(Weapon& newWeapon)
{
	_weapon = &newWeapon;
}

void HumanB::attack(void)
{
	if (!_weapon)
		return ((void)(std::cout << _name << " is unarmed" << std::endl));
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
