/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:51:16 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/31 17:38:04 by oheinzel         ###   ########.fr       */
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
    case 3:
      return (new C());
    default:
      return (NULL);
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p) != NULL)
    std::cout << "A" << std::endl;
  if (dynamic_cast<B*>(p) != NULL)
    std::cout << "B" << std::endl;
  if (dynamic_cast<C*>(p) != NULL)
    std::cout << "C" << std::endl;
}

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
  } catch(std::exception& e) {}
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
  } catch(std::exception& e) {}
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
  } catch(std::exception& e) {}

}

int main(void) {

}
