/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:36:21 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/26 11:17:55 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
  : _name("Jack"), _isSigned(0), _signGrade(150), _execGrade(150) {}

Form::Form(const Form& rhs)
  : _name(rhs._name), _isSigned(rhs._isSigned),
  _signGrade(rhs._signGrade), _execGrade(rhs._execGrade) {}

Form::Form(std::string newName, int newSignGrade, int newExecGrade)
  :_name(newName), _isSigned(0), _signGrade(newSignGrade),
  _execGrade(newExecGrade) {
  if (_signGrade > 150 || _execGrade > 150)
    throw GradeTooLowException();
  if (_signGrade < 1 || _execGrade < 0)
    throw GradeTooHighException();
}

Form::~Form(void) {}

Form&  Form::operator=(const Form& rhs) {
  this->_isSigned = rhs.getIsSigned();
  return (*this);
}

std::string Form::getName(void) const {
  return (_name);
}

bool Form::getIsSigned(void) const {
  return (_isSigned);
}

int Form::getSignGrade(void) const {
  return (_signGrade);
}

int Form::getExecGrade(void) const {
  return (_execGrade);
}

void Form::beSigned(Bureaucrat& signee) {
  if (signee.getGrade() > _signGrade)
    throw GradeTooLowException();
  else
    _isSigned = true;
}

void Form::setIsSigned(bool newIsSigned) {
  _isSigned = newIsSigned;
}

const char* Form::GradeTooHighException::what() const throw() {
  return ("Form: Grade can't be higher than 1");
}

const char* Form::GradeTooLowException::what() const throw() {
  return ("Form: Grade can't be lower than 150");
}

std::ostream& operator<<(std::ostream& out, const Form& rhs) {
  out << "---------------\n";
  out << "Name: " << rhs.getName() << "\n";
  out << "IsSigned: " << rhs.getIsSigned() << "\n";
  out << "SignGrade: " << rhs.getSignGrade() << "\n";
  out << "ExecGrade: " << rhs.getExecGrade() << "\n";
  out << "---------------" << std::endl;
  return (out);
}

