/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:09:41 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/26 16:10:25 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("ShrubberyCreationForm", 25, 5), _target("Nala") {}

ShrubberyCreationForm::ShrubberyCreationForm
(const ShrubberyCreationForm& rhs) : AForm(rhs), _target(rhs._target) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget)
 : AForm("ShrubberyCreationForm", 25, 5), _target(newTarget) {
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=
(const ShrubberyCreationForm& rhs) {
  this->_target = rhs.getTarget();
  this->_isSigned = rhs.getIsSigned();
  return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const {
  return (_target);
}

void ShrubberyCreationForm::setTarget(std::string newTarget) {
  _target = newTarget;
}

std::ostream& operator<<(std::ostream& out,
const ShrubberyCreationForm& rhs) {
  out << "---------------\n";
  out << "Name: " << rhs.getName() << "\n";
  out << "Target: " << rhs.getTarget() << "\n";
  out << "IsSigned: " << rhs.getIsSigned() << "\n";
  out << "SignGrade: " << rhs.getSignGrade() << "\n";
  out << "ExecGrade: " << rhs.getExecGrade() << "\n";
  out << "---------------" << std::endl;
  return (out);
}
