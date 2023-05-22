/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:44:21 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 14:02:55 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
}

Cure::Cure(const Cure& rhs) : AMateria(rhs) {
  *this = rhs;
}

Cure::~Cure(void) {
}

Cure&  Cure::operator=(const Cure& rhs) {
  (void)rhs;
  return (*this);
}

AMateria* Cure::clone(void) const {
  return (new Cure());
}

void Cure::use(ICharacter& target) {
 std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

