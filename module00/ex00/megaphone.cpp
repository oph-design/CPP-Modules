/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:15:37 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/15 18:29:41 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int	main(int argc, char **argv)
{
	unsigned int	i = -1;
	unsigned int	j = -1;

	if (argc == 1)
		return (std::cout << "* LOUD UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	while (argv[++i])
	{
		while (argv[i][++j])
			argv[i][j] = toupper(argv[i][j]);
		j = -1;
	}
	i = 1;
	while (argv[i])
		std::cout << argv[i++];
	std::cout << "\n";
	return (0);
}
