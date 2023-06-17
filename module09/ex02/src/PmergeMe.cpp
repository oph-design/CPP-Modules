/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:08:05 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/17 16:23:35 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _vec(pair_vec()), _dq(pair_dq()), _strag(NULL) {}

PmergeMe::PmergeMe(const PmergeMe& rhs) : _strag(NULL) {
  *this = rhs;
}

PmergeMe::PmergeMe(int argc, char **argv)
  : _vec(pair_vec()), _dq(pair_dq()), _strag(NULL) {
  std::pair<int, int> current;

  for (int i = 0; i < argc; ++i) {
    if (argv[i + 1]) {
      current.first = std::atoi(argv[i++]);
      current.second = std::atoi(argv[i]);
    } else {
      _strag = new int;
      *_strag = std::atoi(argv[i]);
      continue;
    }
    if (current.first < current.second)
      swap(current.first, current.second);
    _vec.push_back(current);
    _dq.push_back(current);
  }
  std::cout << "Before: ";
  for (int i = 0; i < argc; ++i)
    std::cout << argv[i] << " ";
  std::cout << std::endl;
}

PmergeMe::~PmergeMe(void) {
  delete _strag;
}

PmergeMe&  PmergeMe::operator=(const PmergeMe& rhs) {
  delete _strag;
  if (rhs._strag)
    _strag = new int;
  *_strag = *(rhs._strag);
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

void PmergeMe::mergeAndInsertVec(void) {
  std::vector<int> vec_res;
  clock_t start;
  float time;

  start = clock();
  sort_pairs(_vec);
  for (pair_vec::iterator it = _vec.begin(); it < _vec.end(); ++it)
    vec_res.push_back(it->first);
  for (pair_vec::iterator it = _vec.begin(); it < _vec.end(); ++it)
    insertIntoContainer(vec_res, it->second);
  if (_strag != NULL)
    insertIntoContainer(vec_res, *_strag);
  time = (clock() - start) * 1000000 / CLOCKS_PER_SEC ;
  std::cout << "After: ";
  for (size_t i = 0; i < vec_res.size(); ++i)
    std::cout << vec_res[i] << " ";
  std::cout << std::endl;
  std::cout << "Time to process a range of " << vec_res.size();
  std::cout << " elements with std::vector : " << std::fixed << time;
  std::cout << " us" << std::endl;
}

void PmergeMe::mergeAndInsertDq(void) {
  std::deque<int> dq_res;
  clock_t start;
  float time;

  start = clock();
  sort_pairs(_dq);
  for (pair_dq::iterator it = _dq.begin(); it < _dq.end(); ++it)
    dq_res.push_back(it->first);
  for (pair_dq::iterator it = _dq.begin(); it < _dq.end(); ++it)
    insertIntoContainer(dq_res, it->second);
  if (_strag != NULL)
    insertIntoContainer(dq_res, *_strag);
  time = (clock() - start) * 1000000 / CLOCKS_PER_SEC;
  std::cout << "Time to process a range of " << dq_res.size();
  std::cout << " elements with std::deque : " << std::fixed << time;
  std::cout << " us" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const PmergeMe& rhs) {
  (void)rhs;
  out << "---------------\n";
  out << "---------------" << std::endl;
  return (out);
}
