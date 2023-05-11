/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:31:10 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/11 10:17:10 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
	index = 8;
}

Contact::Contact(int id)
{
	index = id;
}

Contact::~Contact(void)
{
}

void	Contact::set_firstname(std::string str)
{
	firstname = str;
}

void	Contact::set_lastname(std::string str)
{
	lastname = str;
}

void	Contact::set_nickname(std::string str)
{
	nickname = str;
}

void	Contact::set_phonenumber(std::string str)
{
	phonenumber = str;
}

void	Contact::set_secret(std::string str)
{
	secret = str;
}

int	Contact::get_index(void)
{
	return (index);
}

void	Contact::format_out(std::string val)
{
	int len = val.length();

	if (len < 10)
		while (++len < 10)
			std::cout << " ";
	std::cout << val.substr(0, 9);
	if (val.length() > 10)
		std::cout << ".";
	if (val.length() == 10)
		std::cout << val.substr(9, 1);
	std::cout << "|";
}

void	Contact::preview(void)
{
	std::cout << "        " << index << "|";
	format_out(firstname);
	format_out(lastname);
	format_out(nickname);
	std::cout << "\n";
}

void	Contact::to_string(void)
{
	std::cout << index << "\n";
	std::cout << firstname << "\n";
	std::cout << lastname << "\n";
	std::cout << nickname << "\n";
	std::cout << phonenumber << "\n";
	std::cout << secret << "\n";
}
