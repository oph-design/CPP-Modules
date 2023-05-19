/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:11:00 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/19 18:15:24 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
  Claptrap Claptrap();
  Claptrap David("David");
  Claptrap Jackson("Jackson");

  Claptrap.attack("David");
  David.attack("Jackson");
  David.beRepaired(10);
  David.takeDamage(5);
  Jackson.setEnergyPoints(0);
  Jackson.attack("Claptrap");
}
