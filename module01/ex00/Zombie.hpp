/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:55:16 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/13 15:17:21 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(void);
		Zombie(const Zombie &rhs);
		Zombie(std::string newName);
		~Zombie(void);
		Zombie& operator=(const Zombie &rhs);
		std::string getName() const;
		void setName(std::string _name);
		void output(void);
		void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
