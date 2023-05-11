/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:31:17 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/11 08:44:17 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook = PhoneBook();
	std::string	input_line;

	while(std::cin)
	{
		std::getline(std::cin, input_line);
		std::cout << input_line << std::endl;
	}
	return (0);
}
