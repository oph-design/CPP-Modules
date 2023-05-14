#ifndef HUMANA_H
# define HUMANA_H
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon&	_weapon;

	public:
		HumanA(std::string newName, Weapon& newWeapon);
		~HumanA(void);
		std::string getName(void) const;
		Weapon getWeapon(void) const;
		void setName(std::string _name);
		void setWeapon(Weapon _weapon);
		void attack(void);
};

#endif
