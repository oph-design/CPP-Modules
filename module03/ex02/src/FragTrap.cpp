/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:29:05 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/20 14:57:36 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
  std::cout << "Default Constructor \033[1m(from Fragtrap)\033[0m called!";
  std::cout << std::endl;
  _name = "FragTrap";
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
}

FragTrap::FragTrap(std::string newName) : ClapTrap(newName) {
  std::cout << "Parameterized Constructor \033[1m(from Fragtrap)\033[0m";
  std::cout << " called!" << std::endl;
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs){
  std::cout << "Copy Constructor \033[1m(from Fragtrap)\033[0m called!";
  std::cout << std::endl;
  *this = rhs;
}

FragTrap::~FragTrap(void) {
  std::cout << "Destructor \033[1m(from Fragtrap)\033[0m called!";
  std::cout << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
  this->_name = rhs.getName();
  this->_hitPoints = rhs.getHitPoints();
  this->_energyPoints = rhs.getEnergyPoints();
  this->_attackDamage = rhs.getAttackDamage();
  return (*this);
}

void FragTrap::highFiveGuys(void) {
  if (_energyPoints < 1 || _hitPoints < 1)
    return (outOfEnergy());
  std::cout << "\033[0;32m" << _name << " is asking for a High Five ... ";
  std::cout << "a positive High Five" << "\033[0m" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const FragTrap& rhs) {
  out << "---------------\n";
  out << "name: " << rhs.getName() << "\n";
  out << "EnergyPoints: " << rhs.getEnergyPoints() << "\n";
  out << "HitPoints: " << rhs.getHitPoints() << "\n";
  out << "AttackDamage: " << rhs.getAttackDamage() << "\n";
  out << "---------------" << std::endl;
  return (out);
}

