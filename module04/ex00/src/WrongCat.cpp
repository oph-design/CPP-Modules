/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:08:22 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/21 13:08:24 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
  :  Animal("WrongCat") {
  std::cout << "\033[1;33mWrongCat born\033[0m" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) {
  *this = rhs;
  std::cout << "\033[1;33mWrongCat cloned\033[0m" << std::endl;
}

WrongCat::~WrongCat(void) {
  std::cout << "\033[1;33mWrongCat died\033[0m" << std::endl;
}

WrongCat&  WrongCat::operator=(const WrongCat& rhs) {
  this->_type = rhs.getType();
  return (*this);
}

void WrongCat::makeSound(void) const {
  std::cout << "meow meow" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const WrongCat& rhs) {
  out << "---------------\n";
  out << "Type: " << rhs.getType() << "\n";
  out << "---------------" << std::endl;
  return (out);
}

