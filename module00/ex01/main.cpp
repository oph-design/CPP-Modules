/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:31:17 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/11 09:45:21 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string	get_value(std::string val_name)
{
	std::string	input;
	std::cout << "enter contacts " << val_name << ":\n";
	std::getline(std::cin, input);
	return (input);
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
	(*phonebook).get_contact(i).to_string();
	if (++i == 8)
		i = 0;
}

void	search_pb(PhoneBook phonebook)
{
	std::string	input;

	phonebook.show_book();
	std::cout << "enter index of desired contact:" << "\n";
	std::getline(std::cin, input);
	phonebook.get_contact(std::stoi(input)).to_string();
}

int	main(void)
{
	std::string	input_line;
	PhoneBook	phonebook = PhoneBook();

	while(1)
	{
		std::getline(std::cin, input_line);
		if (!input_line.compare("ADD"))
			add_contact(&phonebook);
		else if (!input_line.compare("SEARCH"))
			search_pb(phonebook);
		else if (!input_line.compare("EXIT"))
			break ;
		else
			std::cout << "enter ADD, SEARCH or EXIT" << "\n";
	}
	return (0);
}
