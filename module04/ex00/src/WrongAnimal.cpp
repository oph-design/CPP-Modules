/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:31:41 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 16:31:59 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
  : _type("WrongAnimal") {
  std::cout << "\033[1mWrongAnimal born\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) {
  *this = rhs;
  std::cout << "\033[1mWrongAnimal cloned\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string newType)
  : _type(newType) {
  std::cout << "\033[1mspecific WrongAnimal born\033[0m" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "\033[1mWrongAnimal died\033[0m" << std::endl;
}

WrongAnimal&  WrongAnimal::operator=(const WrongAnimal& rhs) {
  this->_type = rhs.getType();
  return (*this);
}

std::string WrongAnimal::getType(void) const {
  return (_type);
}

void WrongAnimal::setType(std::string newType) {
  _type = newType;
}

void WrongAnimal::makeSound(void) const {
  std::cout << "blanc blanc" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const WrongAnimal& rhs) {
  out << "---------------\n";
  out << "Type: " << rhs.getType() << "\n";
  out << "---------------" << std::endl;
  return (out);
}

