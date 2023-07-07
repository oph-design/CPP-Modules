/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:08:05 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/07 08:50:14 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _vec(pair_vec()), _dq(pair_dq()), _strag(NULL) {}

PmergeMe::PmergeMe(const PmergeMe& rhs) : _strag(NULL) {
  *this = rhs;
}

PmergeMe::PmergeMe(int argc, char **argv)
  : _vec(pair_vec()), _dq(pair_dq()), _strag(NULL) {
  int num;

  if (argc % 2 != 0) {
    _strag = new int;
    *_strag = std::atoi(argv[argc - 1]);
  }
  _begins.first = initSortedPairs(argv, argc, _vec);
  _begins.second = initSortedPairs(argv, argc, _dq);
  std::cout << "Before: ";
  for (int i = 0; i < argc; ++i) {
    std::istringstream(std::string(argv[i])) >> num;
    std::cout << num << " ";
  }
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
  this->_vec = rhs._vec;
  this->_dq = rhs._dq;
  return (*this);
}

void PmergeMe::mergeAndInsertVec(void) {
  int_vec res;
  clock_t start;
  float time;

  start = clock();
  mergeSort<pair_vec::iterator, pair_vec >(_vec.begin(), _vec.end());
  for (pair_vec::iterator it = _vec.begin(); it < _vec.end(); ++it)
    res.push_back(it->first);
  for (pair_vec::iterator it = _vec.begin(); it < _vec.end(); ++it)
    bnSort<int_vec, int_vec::iterator>(res, res.begin(), res.end(),it->second);
  if (_strag != NULL)
    bnSort<int_vec, int_vec::iterator>(res, res.begin(), res.end(), *_strag);
  time = ((clock() - start) + _begins.first) * 1000000 / CLOCKS_PER_SEC ;
  std::cout << "After:  ";
  for (size_t i = 0; i < res.size(); ++i)
    std::cout << res[i] << " ";
  std::cout << std::endl;
  std::cout << "Time to process a range of " << res.size();
  std::cout << " elements with std::vector : " << std::fixed << time;
  std::cout << " us" << std::endl;
}

void PmergeMe::mergeAndInsertDq(void) {
  int_dq res;
  clock_t start;
  float time;

  start = clock();
  mergeSort<pair_dq::iterator, pair_dq>(_dq.begin(), _dq.end());
  for (pair_dq::iterator it = _dq.begin(); it < _dq.end(); ++it)
    res.push_back(it->first);
  for (pair_dq::iterator it = _dq.begin(); it < _dq.end(); ++it)
    bnSort<int_dq, int_dq::iterator>(res, res.begin(), res.end(),it->second);
  if (_strag != NULL)
    bnSort<int_dq, int_dq::iterator>(res, res.begin(), res.end(), *_strag);
  time = ((clock() - start) + _begins.second) * 1000000 / CLOCKS_PER_SEC;
  std::cout << "Time to process a range of " << res.size();
  std::cout << " elements with std::deque : " << std::fixed << time;
  std::cout << " us" << std::endl;
}

bool operator<=(const std::pair<int, int> left,
                const std::pair<int, int> right) {
  return (left.first <= right.first);
}
