/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:31:10 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/11 21:03:28 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

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

std::string	Contact::format(std::string val)
{
	if (val.length() == 10)
		return (val.substr(0, 10));
	if (val.length() > 10)
		return (val.substr(0, 9) + ".");
	return (val);
}

void	Contact::preview(void)
{
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << format(firstname) << "|";
	std::cout << std::setw(10) << format(lastname) << "|";
	std::cout << std::setw(10) << format(nickname) << "|";
	std::cout << std::endl;
}

void	Contact::to_string(void)
{
	std::cout << "index:		" << index << std::endl;
	std::cout << "firstname:	" << firstname << std::endl;
	std::cout << "lastname:	" << lastname << std::endl;
	std::cout << "nickname:	" << nickname << std::endl;
	std::cout << "phonenumber:	" << phonenumber << std::endl;
	std::cout << "darkest secret:	" << secret << std::endl;
}
