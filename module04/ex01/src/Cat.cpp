/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:08:11 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 16:34:04 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)  :  Animal("Cat") {
  _brain = new Brain();
  std::cout << "\033[1;33mCat born\033[0m" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs) {
  *this = rhs;
  std::cout << "\033[1;33mCat cloned\033[0m" << std::endl;
}

Cat::~Cat(void) {
  delete _brain;
  std::cout << "\033[1;33mCat died\033[0m" << std::endl;
}

Cat&  Cat::operator=(const Cat& rhs) {
  delete this->_brain;
  this->_brain = new Brain(*(rhs._brain));
  this->_type = rhs.getType();
  return (*this);
}

void Cat::makeSound(void) const {
  std::cout << "meow meow" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Cat& rhs) {
  out << "---------------\n";
  out << "Type: " << rhs.getType() << "\n";
  out << "---------------" << std::endl;
  return (out);
}
