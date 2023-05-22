/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:31:56 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 20:13:49 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  delete j;
  delete i;
  Dog n;
  Dog m(n);
  std::cout << "brain ptr n: " << n.getBrain() << std::endl;
  std::cout << "brain ptr m: " << m.getBrain() << std::endl;

  return (0);
}
