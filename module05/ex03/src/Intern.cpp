/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:52:48 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/27 14:37:56 by oheinzel         ###   ########.fr       */
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
  unsigned int i = 0;
  AForm *res = nullptr;
  std::string type[3] = {"robotomy request", "presidential pardon",
                        "shrubbery creation"};

  while(i < 3 && name.compare(type[i]))
    i++;
  switch (i)
  {
    case 0:
      res = new RobotomyRequestForm(target); break;
    case 1:
      res = new PresidentialPardonForm(target); break;
    case 2:
      res = new ShrubberyCreationForm(target); break;
    default:
      std::cout << name << " isn't a valid form" << std::endl; return res;
  }
  std::cout << "Intern creates " << name << std::endl;
  return (res);
}
