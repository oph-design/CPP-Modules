/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:08:05 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/17 11:47:07 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _vec(std::vector<int>()), _dq(std::deque<int>()) {}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
  *this = rhs;
}

PmergeMe::PmergeMe(int argc, char **argv)
  : _vec(std::vector<int>()), _dq(std::deque<int>()) {
  for (int i = 0; i < argc; ++i)
    _vec.push_back(std::atoi(argv[i]));
  for (int i = 0; i < argc; ++i)
    _dq.push_back(std::atoi(argv[i]));
}

PmergeMe::~PmergeMe(void) {}

PmergeMe&  PmergeMe::operator=(const PmergeMe& rhs) {
  this->_vec = rhs.getVec();
  this->_dq = rhs.getDq();
  return (*this);
}

std::vector<int> PmergeMe::getVec(void) const {
  return (_vec);
}

std::deque<int> PmergeMe::getDq(void) const {
  return (_dq);
}

void PmergeMe::setVec(std::vector<int> newVec) {
  _vec = newVec;
}
void PmergeMe::setDq(std::deque<int> newDq) {
  _dq = newDq;
}

void PmergeMe::mergeAndInsert(void) {
  mergeInsertionSort<std::vector<int>::iterator, std::vector<int> >
    (_vec.begin(), _vec.end() - 1);
  for (size_t i = 0; i < _vec.size(); ++i)
    std::cout << _vec[i] << std::endl;
  mergeInsertionSort<std::deque<int>::iterator, std::deque<int> >
    (_dq.begin(), _dq.end() - 1);
  for (size_t i = 0; i < _dq.size(); ++i)
    std::cout << _dq[i] << std::endl;
}

std::ostream& operator<<(std::ostream& out, const PmergeMe& rhs) {
  (void)rhs;
  out << "---------------\n";
  out << "---------------" << std::endl;
  return (out);
}
