#ifndef WEAPON_H
# define WEAPON_H
# include <iostream>
# include <string>

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(void);
		Weapon(std::string newType);
		~Weapon(void);
		std::string getType(void) const;
		void setType(std::string _type);
		void output(void);
};

#endif
