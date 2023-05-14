#ifndef HUMANB_H
# define HUMANB_H
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon	*_weapon;

	public:
		HumanB(std::string newName);
		~HumanB(void);
		std::string getName(void) const;
		Weapon getWeapon(void) const;
		void setName(std::string _name);
		void setWeapon(Weapon &_weapon);
		void attack(void);
};

#endif
