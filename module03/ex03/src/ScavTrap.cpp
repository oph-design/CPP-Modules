/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:22:59 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/20 16:24:23 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
  std::cout << "Default Constructor \033[1m(from Scavtrap)\033[0m called!";
  std::cout << std::endl;
  _name = "ScavTrap";
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName) {
  std::cout << "Parameterized Constructor \033[1m(from Scavtrap)\033[0m";
  std::cout << " called!" << std::endl;
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) : ClapTrap(rhs) {
  std::cout << "Copy Constructor \033[1m(from Scavtrap)\033[0m called!";
  std::cout << std::endl;
  *this = rhs;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "Destructor \033[1m(from Scavtrap)\033[0m called!";
  std::cout << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
  this->_name = rhs.getName();
  this->_hitPoints = rhs.getHitPoints();
  this->_energyPoints = rhs.getEnergyPoints();
  this->_attackDamage = rhs.getAttackDamage();
  return (*this);
}

void ScavTrap::attack(const std::string& target) {
  if (_energyPoints < 1 || _hitPoints < 1)
    return (outOfEnergy());
  _energyPoints -= 1;
  std::cout << "\033[0;32m" << _name << ", a ScavTrap Object, attacks ";
  std::cout << target << " causing " << _attackDamage << " points of damage!";
  std::cout << std::endl << "\033[0m";
}

void ScavTrap::guardGate(void) {
  if (_energyPoints < 1 || _hitPoints < 1)
    return (outOfEnergy());
  std::cout << "\033[0;32m" << _name << " is now in Gate-Keeper-Mode ... ";
  std::cout << "whatever that means" << "\033[0m" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const ScavTrap& rhs) {
  out << "---------------\n";
  out << "name: " << rhs.getName() << "\n";
  out << "EnergyPoints: " << rhs.getEnergyPoints() << "\n";
  out << "HitPoints: " << rhs.getHitPoints() << "\n";
  out << "AttackDamage: " << rhs.getAttackDamage() << "\n";
  out << "---------------" << std::endl;
  return (out);
}
