/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:56:41 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/24 10:45:27 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"
# include "Character.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "MateriaSource.hpp"

int main(void) {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  me->unequip(1);
  me->use(1, *bob);
  Character mitch("mitch");
  tmp = src->createMateria("ice");
  mitch.equip(tmp);
  Character clone(mitch);
  clone.use(0, *bob);
  mitch.unequip(0);
  clone.use(0, *bob);
  mitch = clone;
  delete bob;
  delete me;
  delete src;
  return 0;
}

