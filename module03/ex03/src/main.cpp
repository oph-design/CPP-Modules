/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:11:00 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/19 21:49:04 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
  DiamondTrap Fragtrap;
  DiamondTrap David("David");
  DiamondTrap Jackson("Jackson");

  std::cout << David;
  Fragtrap.attack("David");
  David.attack("Jackson");
  David.beRepaired(10);
  David.takeDamage(5);
  David.whoAmI();
  std::cout << David;
  Jackson.setEnergyPoints(0);
  Jackson.attack("Claptrap");
}
