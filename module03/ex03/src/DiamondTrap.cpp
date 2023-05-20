/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:51:05 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/20 16:30:31 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap(){
  std::cout << "Default Constructor \033[1m(from Diamondtrap)\033[0m called!";
  std::cout << std::endl;
  _name = "DiamondTrap";
  ClapTrap::_name = _name + "_clap_name";
  _hitPoints = FragTrap::_hitPoints;
  _energyPoints = ScavTrap::_energyPoints;
  _attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs)
  : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs) {
  std::cout << "Copy Constructor \033[1m(from Diamondtrap)\033[0m called!";
  std::cout << std::endl;
  *this = rhs;
}

DiamondTrap::DiamondTrap(std::string newName)
  : ScavTrap(), FragTrap() {
  std::cout << "Parameterized Constructor \033[1m(from Diamondtrap)\033[0m";
  std::cout << " called!" << std::endl;
  _name = newName;
  ClapTrap::_name = _name + "_clap_name";
  _hitPoints = FragTrap::_hitPoints;
  _energyPoints = ScavTrap::_energyPoints;
  _attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "Destructor \033[1m(from Diamondtrap)\033[0m called!";
  std::cout << std::endl;
}

DiamondTrap&  DiamondTrap::operator=(const DiamondTrap& rhs) {
  this->_name = rhs.getName();
  this->_hitPoints = rhs.getHitPoints();
  this->_energyPoints = rhs.getEnergyPoints();
  this->_attackDamage = rhs.getAttackDamage();
  return (*this);
}

std::string DiamondTrap::getName(void) const {
  return (_name);
}

void DiamondTrap::setName(std::string newName) {
  _name = newName;
}

void DiamondTrap::whoAmI(void) {
  std::cout << "\033[0;36mDiamondtrap name: " << _name << "\n";
  std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
  std::cout << "\033[0m";
}

std::ostream& operator<<(std::ostream& out, const DiamondTrap& rhs) {
  out << "---------------\n";
  out << "name: " << rhs.getName() << "\n";
  out << "EnergyPoints: " << rhs.getEnergyPoints() << "\n";
  out << "HitPoints: " << rhs.getHitPoints() << "\n";
  out << "AttackDamage: " << rhs.getAttackDamage() << "\n";
  out << "---------------" << std::endl;
  return (out);
}
