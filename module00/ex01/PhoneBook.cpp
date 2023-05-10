/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:31:21 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/10 18:51:24 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	int	i = 0;

	while (i < 8)
		contacts[i++] = new Contact();
}

PhoneBook::PhoneBook(const PhoneBook &pb)
{
	*this = pb;
}

PhoneBook & PhoneBook::operator = (PhoneBook &pb)
{
	int	i = 0;

	while (i < 8)
	{
		contacts[i] = pb.get_contact(i);
		i++;
	}
	return (*this);
}

PhoneBook::~PhoneBook()
{
	int	i = 0;

	while (i < 8)
		delete contacts[i++];
}

void PhoneBook::add_to_book(Contact contact, int pos)
{
	delete	contacts[pos];
	contacts[pos] = &contact;
}

void PhoneBook::show_book(void)
{
	int	i = 0;

	while (i < 8)
		contacts[i++]->preview();
}

Contact PhoneBook::get_contact(int pos)
{
	return (*contacts[pos]);
}
