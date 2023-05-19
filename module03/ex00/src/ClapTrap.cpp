/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:39:34 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/19 17:11:03 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
  : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
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

void ClapTrap::attack(const std::string& target) {
  if (_energyPoints < 1 || _hitPoints < 1)
    return ((void)(std::cout << _name << " out of energy" << std::endl));
  _energyPoints -= 1;
  std::cout << _name << " attacks " << target;
  std::cout << " causing " << _attackDamage << " points of damage!";
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hitPoints -= amount;
  if (_hitPoints < 0)
    _hitPoints = 0;
  std::cout << _name << " got attacked";
  std::cout << " taking " << amount << " points of damage!";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoints < 1 || _hitPoints < 1)
    return ((void)(std::cout << _name << " out of energy" << std::endl));
  _energyPoints -= 1;
  std::cout << _name << " repaires itself";
  std::cout << " regaining " << amount << " of hitPoints!";
}
