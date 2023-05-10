/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:31:14 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/10 18:00:38 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>

class Contact
{
	private:
		int			index;
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenumber;
		std::string	secret;
	public:
		Contact(void);
		Contact(int id);
		Contact(const Contact &c);
		Contact & operator = (const Contact &c);
		~Contact(void);
		void set_firstname(std::string str);
		void set_lastname(std::string str);
		void set_nickname(std::string str);
		void set_phonenumber(std::string str);
		void set_secret(std::string str);
		int get_index(void);
		void preview(void);
		void to_string(void);
};

#endif
