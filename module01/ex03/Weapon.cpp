#include "Weapon.hpp"

Weapon::Weapon(void)
{
	_type = "unarmed";
}

Weapon::Weapon(std::string newType)
	:_type(newType)
{

}

Weapon::~Weapon(void)
{

}

std::string Weapon::getType(void) const
{
	return (_type);
}

void Weapon::setType(std::string newType)
{
	_type = newType;
}
