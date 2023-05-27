/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:58:10 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/27 18:20:44 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  try {
    PresidentialPardonForm pres("Kanye West");
    Bureaucrat joe("Joe Biden", 1);
    Bureaucrat junior("Junior", 150);
    std::cout << pres;
    pres.beSigned(joe);
    pres.execute(joe);
    pres.execute(junior);
  } catch(AForm::GradeTooLowException& e) {
    std::cout << "AForm: Bureaucrat Grade too low" << std::endl;
  }
  try {
    RobotomyRequestForm rob("Rob");
    Bureaucrat joe("Joe Biden", 1);
    Bureaucrat junior("Junior", 150);
    std::cout << rob;
    rob.beSigned(joe);
    rob.execute(joe);
    rob.execute(junior);
  } catch(AForm::GradeTooLowException& e) {
    std::cout << "AForm: Bureaucrat Grade too low" << std::endl;
  }
  try {
    ShrubberyCreationForm shrub("Shrub");
    Bureaucrat joe("Joe Biden", 1);
    Bureaucrat junior("Junior", 150);
    std::cout << shrub;
    shrub.beSigned(joe);
    shrub.execute(joe);
    shrub.execute(junior);
  } catch(AForm::GradeTooLowException& e) {
    std::cout << "AForm: Bureaucrat Grade too low" << std::endl;
  }
  try {
    ShrubberyCreationForm shrub("Shubby");
    RobotomyRequestForm rob("Robby");
    PresidentialPardonForm pres("Donald");
    Bureaucrat junior("Junior", 150);
    Bureaucrat joe("Joe Biden", 1);
    junior.executeForm(shrub);
    junior.executeForm(rob);
    junior.executeForm(pres);
    shrub.beSigned(joe);
    pres.beSigned(joe);
    rob.beSigned(joe);
    junior.executeForm(shrub);
    junior.executeForm(rob);
    junior.executeForm(pres);
    joe.executeForm(shrub);
    joe.executeForm(rob);
    joe.executeForm(pres);
  } catch(AForm::GradeTooLowException& e) {
    std::cout << "AForm: Bureaucrat Grade too low" << std::endl;
  }
  return (0);
}
