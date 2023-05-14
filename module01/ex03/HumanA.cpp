/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:45:51 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/14 15:00:59 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& newWeapon)
	:_name(newName), _weapon(newWeapon)
{

}

HumanA::~HumanA(void)
{

}

std::string HumanA::getName(void) const
{
	return (_name);
}
Weapon HumanA::getWeapon(void) const
{
	return (_weapon);
}

void HumanA::setName(std::string newName)
{
	_name = newName;
}
void HumanA::setWeapon(Weapon newWeapon)
{
	_weapon = newWeapon;
}

void HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

