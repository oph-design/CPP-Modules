/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:51:42 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/21 11:09:33 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
  : _type("Animal") {
  std::cout << "\033[1mAnimal born\033[0m" << std::endl;
}

Animal::Animal(const Animal& rhs) {
  *this = rhs;
  std::cout << "\033[1mAnimal cloned\033[0m" << std::endl;
}

Animal::Animal(std::string newType)
  : _type(newType) {
  std::cout << "\033[1mspecific Animal born\033[0m" << std::endl;
}

Animal::~Animal(void) {
  std::cout << "\033[1mAnimal died\033[0m" << std::endl;
}

Animal&  Animal::operator=(const Animal& rhs) {
  this->_type = rhs.getType();
  return (*this);
}

std::string Animal::getType(void) const {
  return (_type);
}

void Animal::setType(std::string newType) {
  _type = newType;
}

void Animal::makeSound(void) const {
  std::cout << "blanc blanc" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Animal& rhs) {
  out << "---------------\n";
  out << "Type: " << rhs.getType() << "\n";
  out << "---------------" << std::endl;
  return (out);
}

