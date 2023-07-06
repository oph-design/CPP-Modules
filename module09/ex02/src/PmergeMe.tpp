/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:45:14 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/06 17:14:10 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

template <typename Iterator, typename Sequence>
void PmergeMe::merge(Iterator begin, Iterator mid, Iterator end) {
  Sequence left(begin, mid);
  Sequence right(mid, end);
  Iterator leftIt = left.begin();
  Iterator rightIt = right.begin();
  Iterator mergeIt = begin;

  while (leftIt != left.end() && rightIt != right.end()) {
    if (*leftIt <= *rightIt) *mergeIt = *(leftIt++);
    else *mergeIt = *(rightIt++);
    ++mergeIt;
  }
  while (leftIt != left.end())
    *(mergeIt++) = *(leftIt++);
  while (rightIt != right.end())
    *(mergeIt++) = *(rightIt++);
}

template <typename Iterator, typename Sequence>
void PmergeMe::mergeSort(Iterator first, Iterator last) {
  if (std::distance(first, last) > 1) {
    Iterator mid = first;
    std::advance(mid, std::distance(first, last) / 2);
    mergeSort<Iterator, Sequence>(first, mid);
    mergeSort<Iterator, Sequence>(mid, last);
    merge<Iterator, Sequence>(first, mid, last);
  }
}

template <typename Container>
void PmergeMe::insertIntoContainer(Container& vec, int value) {
  typename Container::iterator it = std::lower_bound(vec.begin(), vec.end(), value);
  vec.insert(it, value);
}

#endif
