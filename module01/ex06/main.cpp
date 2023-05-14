/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:54:03 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/14 21:28:39 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	int i = -1;
	Harl harl = Harl();
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2)
		return (std::cerr << "[ Wrong number of args ]\n", 0);
	while (i < 4 && std::string(argv[1]).compare(levels[++i]));
	switch (i)
	{
		case 0:
			harl.complain("DEBUG");
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case 1:
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case 2:
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]";
			break;
	}
	std::cout << std::endl;
	return (0);
}
