/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:51:16 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/31 22:15:48 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
  std::srand(std::time(NULL));

  switch (std::rand() % 3) {
    case 0:
      return (new A());
    case 1:
      return (new B());
    case 2:
      return (new C());
    default:
      throw std::exception();
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "Class Type of Pointer is A" << std::endl;
  if (dynamic_cast<B*>(p))
    std::cout << "Class Type of Pointer is B" << std::endl;
  if (dynamic_cast<C*>(p))
    std::cout << "Class Type of Pointer is C" << std::endl;
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "Class Type of Reference is A" << std::endl;
  } catch(std::exception& e) {}
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "Class Type of Reference is B" << std::endl;
  } catch(std::exception& e) {}
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "Class Type of Reference is C" << std::endl;
  } catch(std::exception& e) {}

}

int main(void) {
  try {
    Base *test = generate();
    identify(test);
    identify(*test);
    delete test;
  } catch (std::exception& e) {
    std::cerr << "random fail occurred" << std::endl;
  }
}
