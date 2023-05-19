#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
  : _name(0), _hitPoints(0), _energyPoints(0), _attackDamage(0) {
}

ClapTrap::ClapTrap(const ClapTrap& rhs) {
  *this = rhs;
}

ClapTrap::ClapTrap(std::string newName, int newHitPoints,
                int newEnergyPoints, int newAttackDamage)
                :_name(newName), _hitPoints(newHitPoints),
                _energyPoints(newEnergyPoints), _attackDamage(newAttackDamage) {
}

ClapTrap::~ClapTrap(void) {
}

ClapTrap&  ClapTrap::operator=(const ClapTrap& rhs) {
  this->_name = rhs.getName();
  this->_hitPoints = rhs.getHitPoints();
  this->_energyPoints = rhs.getEnergyPoints();
  this->_attackDamage = rhs.getAttackDamage();
  return (*this);
}

std::string ClapTrap::getName(void) const {
  return (_name);
}
int ClapTrap::getHitPoints(void) const {
  return (_hitPoints);
}
int ClapTrap::getEnergyPoints(void) const {
  return (_energyPoints);
}
int ClapTrap::getAttackDamage(void) const {
  return (_attackDamage);
}

void ClapTrap::setName(std::string newName) {
  _name = newName;
}
void ClapTrap::setHitPoints(int newHitPoints) {
  _hitPoints = newHitPoints;
}
void ClapTrap::setEnergyPoints(int newEnergyPoints) {
  _energyPoints = newEnergyPoints;
}
void ClapTrap::setAttackDamage(int newAttackDamage) {
  _attackDamage = newAttackDamage;
}

std::string ClapTrap::toString(void) {
  std::string string = "ClapTrap:\n";
  string = string + "name : " + _name + "\n";
  string = string + "hitPoints : " + std::to_string(_hitPoints) + "\n";
  string = string + "energyPoints : " + std::to_string(_energyPoints) + "\n";
  string = string + "attackDamage : " + std::to_string(_attackDamage) + "\n";
  return (string);
}

