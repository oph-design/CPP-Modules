/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:58:10 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/27 14:51:45 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat bob("Bob", 1);
    std::cout << bob;
    Bureaucrat bob2(bob);
    std::cout << bob2;
    Bureaucrat tyler("Tyler", 150);
    std::cout << tyler;
    tyler = bob;
    std::cout << tyler;
    bob.incrementGrade();
  } catch (Bureaucrat::GradeTooHighException& gthe) {
    std::cout << gthe.what() << std::endl;
  }
  try {
    Bureaucrat test("Test", 151);
  } catch (Bureaucrat::GradeTooLowException& gtle) {
    std::cout << gtle.what() << std::endl;
  }
  return (0);
}
