/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:36:21 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/26 14:02:21 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void)
  : _name("Jack"), _isSigned(0), _signGrade(150), _execGrade(150) {}

AForm::AForm(const AForm& rhs)
  : _name(rhs._name), _isSigned(rhs._isSigned),
  _signGrade(rhs._signGrade), _execGrade(rhs._execGrade) {}

AForm::AForm(std::string newName, int newSignGrade, int newExecGrade)
  :_name(newName), _isSigned(0), _signGrade(newSignGrade),
  _execGrade(newExecGrade) {
  if (_signGrade > 150 || _execGrade > 150)
    throw GradeTooLowException();
  if (_signGrade < 1 || _execGrade < 0)
    throw GradeTooHighException();
}

AForm::~AForm(void) {}

AForm&  AForm::operator=(const AForm& rhs) {
  this->_isSigned = rhs.getIsSigned();
  return (*this);
}

std::string AForm::getName(void) const {
  return (_name);
}

bool AForm::getIsSigned(void) const {
  return (_isSigned);
}

int AForm::getSignGrade(void) const {
  return (_signGrade);
}

int AForm::getExecGrade(void) const {
  return (_execGrade);
}

void AForm::setIsSigned(bool newIsSigned) {
  _isSigned = newIsSigned;
}

void AForm::beSigned(Bureaucrat& signee) {
  if (signee.getGrade() > _signGrade)
    throw GradeTooLowException();
  else
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
  return ("AForm: Grade can't be higher than 1");
}

const char* AForm::GradeTooLowException::what() const throw() {
  return ("AForm: Grade can't be lower than 150");
}

std::ostream& operator<<(std::ostream& out, const AForm& rhs) {
  out << "---------------\n";
  out << "Name: " << rhs.getName() << "\n";
  out << "IsSigned: " << rhs.getIsSigned() << "\n";
  out << "SignGrade: " << rhs.getSignGrade() << "\n";
  out << "ExecGrade: " << rhs.getExecGrade() << "\n";
  out << "---------------" << std::endl;
  return (out);
}

