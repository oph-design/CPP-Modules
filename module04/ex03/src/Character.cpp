/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:19:07 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/24 10:05:57 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("Char") {
  _inventar[0] = NULL;
  _inventar[1] = NULL;
  _inventar[2] = NULL;
  _inventar[3] = NULL;
}

Character::Character(const Character& rhs) {
  unsigned int i = 0;

  while (i < 4) {
    this->_inventar[i] = NULL;
    if (rhs._inventar[i] != NULL)
      this->_inventar[i] = rhs._inventar[i]->clone();
    i++;
  }
  this->_name = rhs.getName();
}

Character::Character(std::string newName) :_name(newName) {
  _inventar[0] = NULL;
  _inventar[1] = NULL;
  _inventar[2] = NULL;
  _inventar[3] = NULL;
}

Character::~Character(void) {
  delete _inventar[0];
  delete _inventar[1];
  delete _inventar[2];
  delete _inventar[3];
}

Character&  Character::operator=(const Character& rhs) {
  unsigned int i = 0;

  while (i < 4) {
    delete this->_inventar[i];
    this->_inventar[i] = NULL;
    if (rhs._inventar[i] != NULL)
      this->_inventar[i] = rhs._inventar[i]->clone();
    i++;
  }
  this->_name = rhs.getName();
  return (*this);
}

std::string const & Character::getName(void) const {
  return (_name);
}

void Character::equip(AMateria* m) {
  unsigned int i = 0;

  while (_inventar[i] && i < 4)
    i++;
  if (i > 3)
    return;
  _inventar[i] = m;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 3)
    return;
  delete _inventar[idx];
  _inventar[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx > 3 || !_inventar[idx])
    return;
  _inventar[idx]->use(target);
}
