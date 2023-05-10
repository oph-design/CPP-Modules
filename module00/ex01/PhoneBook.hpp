/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:31:24 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/10 18:51:30 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact *contacts[8];
	public:
		PhoneBook(void);
		PhoneBook(const PhoneBook &pb);
		~PhoneBook();
		PhoneBook & operator = (PhoneBook &pb);
		void add_to_book(Contact contact, int pos);
		void show_book(void);
		Contact get_contact(int pos);
};

#endif
