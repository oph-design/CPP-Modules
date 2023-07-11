/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:57:23 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/09 11:46:58 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) : _nums(std::stack<int>()) {}

RPN::RPN(const RPN& rhs) {
  *this = rhs;
}

RPN::RPN(std::string input) : _nums(std::stack<int>()) {
  for (std::string::iterator it = input.begin(); it < input.end(); ++it) {
    if (*it == '*' || *it == '/' || *it == '+' || *it == '-')
      this->_nums.push(calcNext(*it));
    else if (std::isdigit(*it))
      this->_nums.push(*it - 48);
    else if (*it != ' ')
      throw std::runtime_error("Error");
  }
  if (this->_nums.size() != 1)
    throw std::runtime_error("Error");
}

RPN::~RPN(void) {}

RPN&  RPN::operator=(const RPN& rhs) {
  this->_nums = rhs._nums;
  return (*this);
}

std::stack<int> RPN::getNums(void) const {
  return (this->_nums);
}

void RPN::setNums(std::stack<int> newNums) {
  _nums = newNums;
}

int RPN::calcNext(char c) {
  if (this->_nums.size() < 2)
    throw std::runtime_error("Error");
  int n = this->_nums.top();
  this->_nums.pop();
  int m = this->_nums.top();
  this->_nums.pop();
  if (!n && c == '/')
   throw std::runtime_error("Error");
  switch (c) {
    case '+':
      return (m + n);
    case '-':
      return (m - n);
    case '/':
      return (m / n);
    case '*':
      return (m * n);
    default:
      throw std::runtime_error("Error");
  }
}

std::ostream& operator<<(std::ostream& out, const RPN& rhs) {
  out << rhs.getNums().top();
  return (out);
}

