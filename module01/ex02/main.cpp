/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:54:44 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/14 14:11:13 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Address of string:		"<< &string << std::endl;
	std::cout << "Address held by pointer:	" << stringPTR << std::endl;
	std::cout << "Address held by reference:	" << &stringREF << std::endl;
	std::cout << "Value of string:		" << string << std::endl;
	std::cout << "Value pointed to:		" << *stringPTR << std::endl;
	std::cout << "Value referenced:		" << stringREF << std::endl;
	return (0);
}
