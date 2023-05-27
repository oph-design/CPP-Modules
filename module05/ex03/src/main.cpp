/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:58:10 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/27 18:28:42 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:58:10 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/27 18:06:44 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {
  try {
    Intern one;
    AForm* test = one.makeForm("presidential pardon", "Kanye West");
    AForm* test2 = one.makeForm("robotomy request", "barry");
    AForm* nll = one.makeForm("generic form", "all");
    if (!nll)
      std::cout << "found null ptr" << std::endl;
    Bureaucrat joe("Joe Biden", 1);
    std::cout << *test;
    (*test).beSigned(joe);
    (*test2).beSigned(joe);
    (*test).execute(joe);
    joe.executeForm(*test2);
    delete test;
    delete test2;
  } catch(AForm::GradeTooLowException& e) {
    std::cout << "AForm: Bureaucrat Grade too low" << std::endl;
  }
  return (0);
}
