#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

class ClapTrap{
 private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

 public:
    ClapTrap(void);
    ClapTrap(const ClapTrap &rhs);
    ClapTrap(std::string newName, int newHitPoints,
            int newEnergyPoints, int newAttackDamage);
    ~ClapTrap(void);
    ClapTrap& operator=(const ClapTrap &rhs);
    std::string getName(void) const;
    int getHitPoints(void) const;
    int getEnergyPoints(void) const;
    int getAttackDamage(void) const;
    void setName(std::string newName);
    void setHitPoints(int newHitPoints);
    void setEnergyPoints(int newEnergyPoints);
    void setAttackDamage(int newAttackDamage);
    std::string toString(void);
};

#endif
