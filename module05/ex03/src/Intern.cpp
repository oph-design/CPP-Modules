/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:52:48 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/26 18:54:46 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& rhs) {
  *this = rhs;
}

Intern::~Intern(void) {}

Intern&  Intern::operator=(const Intern& rhs) {
  return (*this);
}

AForm* makeForm(std::string name, std::string target) {
  if (!name.compare("robotomy request"))
    return (std::cout << "Intern creates " << name << "\n", new RobotomyRequestForm(target));
  if (!name.compare("presidential pardon"))
    return (std::cout << "Intern creates " << name << "\n", new PresidentialPardonForm(target));
  if (!name.compare("shrubbery creation"))
    return (std::cout << "Intern creates " << name << "\n", new ShrubberyCreationForm(target));
  std::cout << "Theres no form named " << name << "\n";
}
