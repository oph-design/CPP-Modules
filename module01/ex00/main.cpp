/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:55:25 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/13 18:00:36 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*z;

	z = newZombie("Rick");
	z->announce();
	randomChump("Carl");
	delete z;
	return (0);
}
