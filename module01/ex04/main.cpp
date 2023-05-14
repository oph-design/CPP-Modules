/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:34:56 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/14 20:04:52 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	writeAndReplace(std::ofstream *outfile, std::string in,
		std::string search, std::string replace)
{
	size_t	needle = in.find(search, 0);

	if (needle == in.npos)
		return ((void)(*outfile << in << "\n"));
	*outfile << in.substr(0, needle) << replace;
	writeAndReplace(outfile, in.substr(needle + search.length(),
	in.length()), search, replace);
}

int	main(int argc, char **argv)
{
	std::string		in;
	std::ifstream	infile;
	std::ofstream	outfile;

	if (argc != 4)
		return (std::cout << "wrong nbr of arguments\n", 1);
	infile.open(argv[1]);
	outfile.open(std::string(argv[1]) + ".replace");
	if (!infile.is_open() || !outfile.is_open())
		return (std::cout << "could not open file\n", 1);
	while (std::getline(infile, in))
		writeAndReplace(&outfile, in, argv[2], argv[3]);
	infile.close();
	outfile.close();
	return (0);
}
