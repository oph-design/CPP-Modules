/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:08:01 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 20:13:06 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
  _brain = new Brain();
  std::cout << "\033[1;33mDog born\033[0m" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs) {
  *this = rhs;
  std::cout << "\033[1;33mDog cloned\033[0m" << std::endl;
}

Dog::~Dog(void) {
  delete _brain;
  std::cout << "\033[1;33mDog died\033[0m" << std::endl;
}

Dog&  Dog::operator=(const Dog& rhs) {
  delete this->_brain;
  this->_brain = new Brain(*(rhs._brain));
  this->_type = rhs.getType();
  return (*this);
}

void Dog::makeSound(void) const {
  std::cout << "bark bark" << std::endl;
}

Brain* Dog::getBrain(void) const {
  return (_brain);
}

std::ostream& operator<<(std::ostream& out, const Dog& rhs) {
  out << "---------------\n";
  out << "Type: " << rhs.getType() << "\n";
  out << "---------------" << std::endl;
  return (out);
}

