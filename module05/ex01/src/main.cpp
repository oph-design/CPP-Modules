/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:58:10 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/27 15:25:38 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  try {
    Form test("testForm", 1, 1);
    std::cout << test;
    Bureaucrat bob("Bob", 2);
    std::cout << bob;
    bob.signForm(test);
    bob.incrementGrade();
    bob.signForm(test);
    std::cout << test;
    test.beSigned(bob);
    bob.decrementGrade();
    Form test2("form", 1, 1);
    test2.beSigned(bob);
  } catch (Form::GradeTooLowException& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Form test("Test", 150, 150);
    std::cout << test;
    Form clone(test);
    std::cout << clone;
    Form exception("ETest", 0, 0);
  } catch (Form::GradeTooHighException& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
