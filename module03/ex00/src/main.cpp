/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:11:00 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/19 18:55:57 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap Claptrap;
  ClapTrap David("David");
  ClapTrap Jackson("Jackson");

  std::cout << David;
  Claptrap.attack("David");
  David.attack("Jackson");
  David.beRepaired(10);
  David.takeDamage(5);
  std::cout << David;
  Jackson.setEnergyPoints(0);
  Jackson.attack("Claptrap");
}
