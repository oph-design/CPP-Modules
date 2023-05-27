/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:07:47 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/27 15:26:16 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Jack"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
  : _name(rhs._name), _grade(rhs._grade) {}

Bureaucrat::Bureaucrat(std::string newName, int newGrade)
  :_name(newName), _grade(newGrade) {
    if (_grade > 150)
      throw GradeTooLowException();
    if (_grade < 0)
      throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat&  Bureaucrat::operator=(const Bureaucrat& rhs) {
  this->_grade = rhs.getGrade();
  return (*this);
}

std::string Bureaucrat::getName(void) const {
  return (_name);
}

int Bureaucrat::getGrade(void) const {
  return (_grade);
}

void Bureaucrat::incrementGrade(void) {
  if (_grade - 1 < 1)
    throw GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade(void) {
  if (_grade + 1 > 150)
    throw GradeTooLowException();
  _grade++;
}

void Bureaucrat::signForm(AForm& form) {
  if (_grade > form.getSignGrade()) {
    std::cout << _name << "couldn't signed " << form.getName();
    std::cout << "because their Grade is too low" << std::endl;
    return ;
  }
  std::cout << _name << " signed " << form.getName() << std::endl;
  form.setIsSigned(true);
}

void Bureaucrat::executeForm(AForm const & form) {
  if (_grade > form.getExecGrade()){
    std::cout << _name << " couldn't execute " << form.getName();
    std::cout << " because their Grade is too low" << std::endl;
    return ;
  }
  form.execute(*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Bureaucrat: Grade can't be higher than 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Bureaucrat: Grade can't be lower than 150");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs) {
  out << rhs.getName() << ", Bureaucrat grade " << rhs.getGrade() << std::endl;
  return (out);
}

