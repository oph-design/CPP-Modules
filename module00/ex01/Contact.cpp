/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:31:10 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/10 18:03:20 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void)
{
	index = 8;
	firstname = NULL;
	lastname = NULL;
	nickname = NULL;
	phonenumber = NULL;
	secret = NULL;
}

Contact::Contact(int id)
{
	index = id;
	firstname = NULL;
	lastname = NULL;
	nickname = NULL;
	phonenumber = NULL;
	secret = NULL;
}

Contact::Contact(const Contact &c)
{
	*this = c;
}

Contact & Contact::operator = (const Contact &c)
{
	firstname = c.get_firstname();
	lastname = c.get_lastname();
	nickname = c.get_nickname();
	phonenumber = c.get_phonenumber();
	secret = c.get_secret();
	return (*this);
}

Contact::~Contact(void)
{
	delete firstname;
	delete lastname;
	delete nickname;
	delete phonenumber;
	delete secret;
}

void Contact::set_firstname(std::string str)
{
	firstname = str;
}

void Contact::set_lastname(std::string str)
{
	lastname = str;
}

void Contact::set_nickname(std::string str)
{
	nickname = str;
}

void Contact::set_phonenumber(std::string str)
{
	phonenumber = str;
}

void Contact::set_secret(std::string str)
{
	secret = str;
}

int Contact::get_index(void)
{
	return (index);
}

void Contact::preview(void)
{
	std::cout << index << "|";
	std::cout << firstname << "|";
	std::cout << lastname << "|";
	std::cout << nickname << "\n";
}

void Contact::to_string(void)
{
	std::cout << index << "\n";
	std::cout << firstname << "\n";
	std::cout << lastname << "\n";
	std::cout << nickname << "\n";
	std::cout << phonenumber << "\n";
	std::cout << secret << "\n";
}
