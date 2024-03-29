/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:08:28 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 17:05:14 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
  : Animal("Dog") {
  std::cout << "\033[1;33mDog born\033[0m" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs) {
  *this = rhs;
  std::cout << "\033[1;33mDog cloned\033[0m" << std::endl;
}

Dog::~Dog(void) {
  std::cout << "\033[1;33mDog died\033[0m" << std::endl;
}

Dog&  Dog::operator=(const Dog& rhs) {
  this->_type = rhs.getType();
  return (*this);
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

