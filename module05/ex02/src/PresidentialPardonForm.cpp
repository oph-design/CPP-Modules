/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:53:08 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/26 17:55:05 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: AForm("PresidentialPardonForm", 25, 5), _target("Nala") {}

PresidentialPardonForm::PresidentialPardonForm
(const PresidentialPardonForm& rhs) : AForm(rhs), _target(rhs._target) {}

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget)
 : AForm("PresidentialPardonForm", 25, 5), _target(newTarget) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm&  PresidentialPardonForm::operator=
(const PresidentialPardonForm& rhs) {
  this->_target = rhs.getTarget();
  this->_isSigned = rhs.getIsSigned();
  return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const {
  return (_target);
}

void PresidentialPardonForm::setTarget(std::string newTarget) {
  _target = newTarget;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
  if (executor.getGrade() > _execGrade)
    throw GradeTooLowException();
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}

std::ostream& operator<<(std::ostream& out,
const PresidentialPardonForm& rhs) {
  out << "---------------\n";
  out << "Name: " << rhs.getName() << "\n";
  out << "Target: " << rhs.getTarget() << "\n";
  out << "IsSigned: " << rhs.getIsSigned() << "\n";
  out << "SignGrade: " << rhs.getSignGrade() << "\n";
  out << "ExecGrade: " << rhs.getExecGrade() << "\n";
  out << "---------------" << std::endl;
  return (out);
}
