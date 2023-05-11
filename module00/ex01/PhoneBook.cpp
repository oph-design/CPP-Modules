/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:31:21 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/11 19:13:14 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::add_to_book(Contact contact, int pos)
{
	contacts[pos] = contact;
}

void PhoneBook::show_book(void)
{
	int	i = 0;

	std::cout << std::setw(10) << std::setfill(' ') << "index|";
	std::cout << std::setw(10) << std::setfill(' ') << "firstname|";
	std::cout << std::setw(10) << std::setfill(' ') << "lastname|";
	std::cout << std::setw(10) << std::setfill(' ') << "nickname|" << std::endl;
	while (i < 8)
	{
		if (contacts[i].get_index() < 8)
			contacts[i].preview();
		i++;
	}
}

Contact PhoneBook::get_contact(int pos)
{
	return (contacts[pos]);
}
