/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:08:01 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/23 11:10:03 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
  : Animal("Dog") {
  _brain = new Brain();
  std::cout << "\033[1;33mDog born\033[0m" << std::endl;
}

Dog::~Dog(void) {
  delete _brain;
  std::cout << "\033[1;33mDog died\033[0m" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs) {
  _brain = new Brain(*(rhs._brain));
  _type = rhs._type;
  std::cout << "\033[1;33mDog cloned\033[0m" << std::endl;
}

Dog&  Dog::operator=(const Dog& rhs) {
  *_brain = *(rhs._brain);
  this->_type = rhs.getType();
  return (*this);
}

Brain* Dog::getBrain(void) const {
  return (_brain);
}

void Dog::makeSound(void) const {
  std::cout << "bark bark" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Dog& rhs) {
  out << "---------------\n";
  out << "Type: " << rhs.getType() << "\n";
  out << "---------------" << std::endl;
  return (out);
}

