/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:32:29 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/12 10:13:03 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _vec(std::vector<int> (0)), _size(0) {}

Span::Span(const Span& rhs) {
  *this = rhs;
}

Span::Span(unsigned int size) :_vec(std::vector<int> (0)), _size(size) {}

Span::~Span(void) {}

Span&  Span::operator=(const Span& rhs) {
  this->_vec = rhs.getVec();
  this->_size = rhs._size;
  return (*this);
}

std::vector<int> Span::getVec(void) const {
  return (_vec);
}

void Span::setVec(std::vector<int> newVec) {
  _vec = newVec;
}

void Span::addNumber(int value) {
  static unsigned int i = 0;

  if (i++ >= _size)
    throw std::runtime_error("limit reached");
  _vec.push_back(value);
}

void Span::addNumberPlusPlus() {
  std::srand(std::time(NULL));

  for (unsigned int i = 0; i < _size - _vec.size(); ++i)
    _vec.push_back(rand());
}

int Span::shortestSpan() {
  std::sort(_vec.begin(), _vec.end());
  std::vector<int>::iterator iter = _vec.begin();
  int tmp, span = INT_MAX;

  if (_vec.size() < 2)
    throw std::runtime_error("too few values");
  while (iter < (_vec.end() - 1)) {
    tmp = *iter;
    iter++;
    tmp -= *iter;
    if (-tmp < span)
      span = -tmp;
  }
  return (span);
}

int Span::longestSpan() {
  std::sort(_vec.begin(), _vec.end());

  if (_vec.size() < 2)
    throw std::runtime_error("too few values");
  return (*(_vec.end() - 1) - *_vec.begin());
}

// std::ostream& operator<<(std::ostream& out, const Span& rhs) {
//   out << "---------------\n";
//   for (std::vector<int>::iterator ptr = rhs.getVec().begin(); ptr < rhs.getVec().end(); ptr++)
//         cout << *ptr << " ";
//   out << "---------------" << std::endl;
//   return (out);
// }

