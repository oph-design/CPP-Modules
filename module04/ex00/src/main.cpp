/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:31:56 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 20:00:47 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  const WrongAnimal* k = new WrongCat();

  std::cout << "\n\033[0;32mvirtual function test\033[0m" << std::endl;
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  std::cout << k->getType() << " " << std::endl;
  i->makeSound();
  j->makeSound();
  k->makeSound();
  meta->makeSound();
  delete meta;
  delete j;
  delete i;
  delete k;
  std::cout << "\n\033[0;32mcopyconstructor test\033[0m" << std::endl;
  Cat a;
  Cat b(a);
  Dog c;
  Dog d(c);
  return (0);
}
