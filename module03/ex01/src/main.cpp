/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:11:00 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/19 20:32:17 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ScavTrap Scavtrap;
  ScavTrap David("David");
  ScavTrap Jackson("Jackson");

  std::cout << David;
  Scavtrap.attack("David");
  David.attack("Jackson");
  David.beRepaired(10);
  David.takeDamage(5);
  David.guardGate();
  std::cout << David;
  Jackson.setEnergyPoints(0);
  Jackson.attack("Claptrap");
}
