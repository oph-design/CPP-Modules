/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:13:09 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 13:57:30 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("Materia") {
}

AMateria::AMateria(std::string const & type) : _type(type) {
}

AMateria::AMateria(const AMateria & rhs) {
  *this = rhs;
}

AMateria& AMateria::operator=(const AMateria & rhs) {
  this->_type = rhs._type;
  return (*this);
}

AMateria::~AMateria(void) {
}

std::string const & AMateria::getType() const {
  return (_type);
}

void AMateria::use(ICharacter& target) {
  std::cout << _type << "gets used on" << target.getName() << std::endl;
}
