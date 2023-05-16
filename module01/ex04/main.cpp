/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:34:56 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/15 13:32:24 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	writeAndReplace(std::ofstream& outfile, std::string search,
		std::string replace, std::string line)
{
	size_t	needle = line.find(search, 0);

	if (needle == line.npos)
		return ((void)(outfile << line << "\n"));
	outfile << line.substr(0, needle) << replace;
	writeAndReplace(outfile, search, replace,
		line.substr(needle + search.length(), line.length()));
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		line;
	std::string		out;

	if (argc != 4)
		return (std::cerr << "wrong nbr of arguments" << std::endl, 1);
	out = std::string(argv[1]).append(".replace");
	if (!std::string(argv[2]).length() || !std::string(argv[3]).length())
		return (std::cerr << "empty string" << std::endl, 1);
	infile.open(argv[1]);
	if (!infile.is_open())
		return (std::cerr << "could not open file" << std::endl, 1);
	outfile.open(out.c_str());
	if (!outfile.is_open())
		return (std::cerr << "could not open file" << std::endl, 1);
	while (std::getline(infile, line))
		writeAndReplace(outfile, argv[2], argv[3], line);
	infile.close();
	outfile.close();
	return (0);
}
