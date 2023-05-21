/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:45:31 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/21 21:56:09 by oheinzel         ###   ########.fr       */
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
  *this = rhs;
}

MateriaSource::~MateriaSource(void) {
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& rhs) {
  unsigned int i = 0;

  while (i < 4)
  {
    delete this->_inventar[i];
    this->_inventar[i] = NULL;
    if (rhs._inventar[i] != NULL)
      this->_inventar[i] = rhs._inventar[i]->clone();
    i++;
  }
  return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
  unsigned int i = 0;

  while (_inventar[i] && i < 4)
    i++;
  if (i > 3)
    return ;
  _inventar[i] = m;
}

AMateria* createMateria(std::string const & type) {
  unsigned int i = 0;

  while (_templates[i].getType().compare(type) && i < 4)
    i++;
  if (i < 4)
    return (_templates[i]->clone());
  return (NULL);
}
