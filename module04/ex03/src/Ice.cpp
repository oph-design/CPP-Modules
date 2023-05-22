/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:41:23 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 14:04:00 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
}

Ice::Ice(const Ice& rhs) : AMateria(rhs) {
  *this = rhs;
}

Ice::~Ice(void) {
}

Ice&  Ice::operator=(const Ice& rhs) {
  (void)rhs;
  return (*this);
}

AMateria* Ice::clone(void) const {
  return (new Ice());
}

void Ice::use(ICharacter& target) {
 std::cout << "* shoots an Icebold at " << target.getName();
 std::cout << " *" << std::endl;
}
