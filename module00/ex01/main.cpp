/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:31:17 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/11 19:14:34 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string	get_value(std::string val_name)
{
	std::string	input;

	while (1)
	{
		std::cout << "enter contacts " << val_name << ": ";
		std::getline(std::cin, input);
		if (!input.length())
			continue ;
		if (!std::cin)
			exit(1);
		return (input);
	}
}

void	add_contact(PhoneBook *phonebook)
{
	static int	i = 0;
	Contact		contact = Contact(i);

	contact.set_firstname(get_value("firstname"));
	contact.set_lastname(get_value("lastname"));
	contact.set_nickname(get_value("nickname"));
	contact.set_phonenumber(get_value("phonenumber"));
	contact.set_secret(get_value("darkest secret"));
	(*phonebook).add_to_book(contact, i);
	if (++i == 8)
		i = 0;
}

void	search_pb(PhoneBook phonebook)
{
	int			index;
	std::string	input;

	phonebook.show_book();
	std::cout << "enter index of desired contact: ";
	std::getline(std::cin, input);
	if (!std::cin)
		exit(1);
	if (input.length() > 1 || !std::isdigit(input.at(0)))
		return ((void)(std::cout << "please enter a single digit" << std::endl));
	index = std::stoi(input);
	if (index > 7 || phonebook.get_contact(index).get_index() == 8)
		return ((void)(std::cout << "no contact with this index" << std::endl));
	phonebook.get_contact(index).to_string();
}

int	main(void)
{
	std::string	input_line;
	PhoneBook	phonebook = PhoneBook();

	while(std::cin)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, input_line);
		if (!input_line.compare("ADD"))
			add_contact(&phonebook);
		else if (!input_line.compare("SEARCH"))
			search_pb(phonebook);
		else if (!input_line.compare("EXIT"))
			break ;
		else
			std::cout << "enter ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}
