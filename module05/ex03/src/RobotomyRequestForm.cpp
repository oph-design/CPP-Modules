/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:07:03 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/26 17:55:20 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
: AForm("RobotomyRequestForm", 72, 45), _target("Nala") {}

RobotomyRequestForm::RobotomyRequestForm
(const RobotomyRequestForm& rhs) : AForm(rhs), _target(rhs._target) {}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget)
 : AForm("RobotomyRequestForm", 72, 45), _target(newTarget) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm&  RobotomyRequestForm::operator=
(const RobotomyRequestForm& rhs) {
  this->_target = rhs.getTarget();
  this->_isSigned = rhs.getIsSigned();
  return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const {
  return (_target);
}

void RobotomyRequestForm::setTarget(std::string newTarget) {
  _target = newTarget;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
  unsigned int prob = rand() % 2;

  if (executor.getGrade() > _execGrade)
    throw GradeTooLowException();
  std::cout << "Brrr Brrr" << std::endl;
  if (!prob)
    return ((void)(std::cout << "Robotomy was unsuccessful" << std::endl));
  std::cout << "Successfully robotomized" << std::endl;
}

std::ostream& operator<<(std::ostream& out,
const RobotomyRequestForm& rhs) {
  out << "---------------\n";
  out << "Name: " << rhs.getName() << "\n";
  out << "Target: " << rhs.getTarget() << "\n";
  out << "IsSigned: " << rhs.getIsSigned() << "\n";
  out << "SignGrade: " << rhs.getSignGrade() << "\n";
  out << "ExecGrade: " << rhs.getExecGrade() << "\n";
  out << "---------------" << std::endl;
  return (out);
}
