/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:45:31 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/24 10:03:12 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
  _templates[0] = NULL;
  _templates[1] = NULL;
  _templates[2] = NULL;
  _templates[3] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& rhs) {
  unsigned int i = 0;

  while (i < 4) {
    this->_templates[i] = NULL;
    if (rhs._templates[i] != NULL)
      this->_templates[i] = rhs._templates[i]->clone();
    i++;
  }
}

MateriaSource::~MateriaSource(void) {
  delete _templates[0];
  delete _templates[1];
  delete _templates[2];
  delete _templates[3];
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& rhs) {
  unsigned int i = 0;

  while (i < 4) {
    delete this->_templates[i];
    this->_templates[i] = NULL;
    if (rhs._templates[i] != NULL)
      this->_templates[i] = rhs._templates[i]->clone();
    i++;
  }
  return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
  unsigned int i = 0;

  while (_templates[i] && i < 4)
    i++;
  if (i > 3)
    return;
  _templates[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
  unsigned int i = 0;

  while (i < 4 && _templates[i] && _templates[i]->getType().compare(type))
    i++;
  if (i < 4)
    return (_templates[i]->clone());
  return (NULL);
}
