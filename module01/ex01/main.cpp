/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:55:25 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/14 13:39:51 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int		n = 8;
	int		i = 0;
	Zombie	*horde = zombieHorde(n, "Dummy");

	while (i < 8)
		horde[i++].announce();
	delete [] horde;
	return (0);
}
