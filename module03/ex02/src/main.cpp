/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:11:00 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/19 20:32:33 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
  FragTrap Fragtrap;
  FragTrap David("David");
  FragTrap Jackson("Jackson");

  std::cout << David;
  Fragtrap.attack("David");
  David.attack("Jackson");
  David.beRepaired(10);
  David.takeDamage(5);
  David.highFiveGuys();
  std::cout << David;
  Jackson.setEnergyPoints(0);
  Jackson.attack("Claptrap");
}
