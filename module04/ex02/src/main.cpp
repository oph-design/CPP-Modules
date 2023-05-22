/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:31:56 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 20:36:10 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  const Dog* j = new Dog();
  const Cat* i = new Cat();

  std::cout << "\n\033[0;32mvirtual function test\033[0m" << std::endl;
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  delete j;
  delete i;

  std::cout << "\n\033[0;32mBrain test\033[0m" << std::endl;
  const Dog* a = new Dog();
  const Cat* b = new Cat();

  delete a;
  delete b;
  Dog n;
  Dog m(n);
  std::cout << "brain ptr n: " << n.getBrain() << std::endl;
  std::cout << "brain ptr m: " << m.getBrain() << std::endl;

  // std::cout << "\n\033[0;32mAbstract test\033[0m";
  // Animal test("Hamster");
  return (0);
}
