/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:08:05 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/07 14:57:26 by oheinzel         ###   ########.fr       */
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

  _begins.first = initSortedPairs(argv, argc, _vec);
  _begins.second = initSortedPairs(argv, argc, _dq);
  if (argc % 2 != 0) {
    _strag = new int;
    *_strag = std::atoi(argv[argc - 1]);
  }
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
  this->_begins = rhs._begins;
  return (*this);
}

void PmergeMe::mergeAndInsertVec(void) {
  int_vec res;
  int_vec jakob;
  clock_t start;
  float time;

  start = clock();
  jakobFactory(jakob, _vec.size());
  mergeSort<pair_vec::iterator, pair_vec >(_vec.begin(), _vec.end());
  insertionSort<int_vec, pair_vec>(res, jakob, _vec);
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
  int_dq jakob;
  clock_t start;
  float time;

  start = clock();
  jakobFactory(jakob, _dq.size());
  mergeSort<pair_dq::iterator, pair_dq>(_dq.begin(), _dq.end());
  insertionSort<int_dq, pair_dq>(res, jakob, _dq);
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
