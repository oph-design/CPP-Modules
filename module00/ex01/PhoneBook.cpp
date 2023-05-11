/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:31:21 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/11 10:16:17 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_to_book(Contact contact, int pos)
{
	contacts[pos] = contact;
}

void PhoneBook::show_book(void)
{
	int	i = 0;

	std::cout << "    index" << "|";
	std::cout << "firstname" << "|";
	std::cout << " lastname" << "|";
	std::cout << " nickname" << "|" << "\n";
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
