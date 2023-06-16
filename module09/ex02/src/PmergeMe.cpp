/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:08:05 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/17 01:06:04 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _vec(pair_vec()), _dq(pair_dq()) {}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
  *this = rhs;
}

PmergeMe::PmergeMe(int argc, char **argv) : _vec(pair_vec()), _dq(pair_dq()) {
  std::pair<int, int> current;

  for (int i = 0; i < argc; ++i) {
    current.first = std::atoi(argv[i++]);
    if (argv[i])
      current.second = std::atoi(argv[i]);
    if (argv[i] && current.first < current.second)
      swap(current.first, current.second);
    _vec.push_back(current);
    _dq.push_back(current);
  }
}

PmergeMe::~PmergeMe(void) {}

PmergeMe&  PmergeMe::operator=(const PmergeMe& rhs) {
  this->_vec = rhs.getVec();
  this->_dq = rhs.getDq();
  return (*this);
}

PmergeMe::pair_vec PmergeMe::getVec(void) const {
  return (_vec);
}

PmergeMe::pair_dq PmergeMe::getDq(void) const {
  return (_dq);
}

void PmergeMe::setVec(pair_vec newVec) {
  _vec = newVec;
}
void PmergeMe::setDq(pair_dq newDq) {
  _dq = newDq;
}

void PmergeMe::mergeAndInsert(void) {
  std::vector<int> vec_res;
  std::deque<int> dq_res;

  for (size_t i = 0; i < _vec.size(); ++i)
    std::cout << _vec[i].first << " " << _vec[i].second << std::endl;
  mergeSort<pair_vec::iterator, pair_vec>(_vec.begin(), _vec.end());
  mergeSort<pair_dq::iterator, pair_dq>(_dq.begin(), _dq.end());
  for (size_t i = 0; i < _vec.size(); ++i)
    vec_res.push_back(_vec[i].first);
  for (size_t i = 0; i < _dq.size(); ++i)
    dq_res.push_back(_dq[i].first);
  for (size_t i = 0; i < _vec.size(); ++i)
    insertOrdered< std::vector<int> >(vec_res, _vec[i].second);
  for (size_t i = 0; i < _dq.size(); ++i)
    insertOrdered< std::deque<int> >(dq_res, _dq[i].second);
  std::cout << vec_res.size() << std::endl;
  for (size_t i = 0; i < vec_res.size(); ++i)
    std::cout << vec_res[i] << std::endl;
}

std::ostream& operator<<(std::ostream& out, const PmergeMe& rhs) {
  (void)rhs;
  out << "---------------\n";
  out << "---------------" << std::endl;
  return (out);
}

