/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:45:14 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/17 01:11:46 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

template <typename Iterator, typename Sequence>
void PmergeMe::merge(Iterator begin, Iterator mid, Iterator end) {
  Sequence temp(begin, end);
  Iterator left = temp.begin();
  Iterator right = mid;
  Iterator current = begin;

  while (left != mid && right != temp.end())
      *current++ = ((*left).first <= (*right).first) ? *left++ : *right++;
  while (left != mid)
      *current++ = *left++;
  while (right != temp.end())
      *current++ = *right++;
}

template <typename Iterator, typename Sequence>
void PmergeMe::mergeSort(Iterator begin, Iterator end) {
  if (distance(begin, end) > 1) {
      Iterator mid = next(begin, distance(begin, end) / 2);
      mergeSort<Iterator, Sequence>(begin, mid);
      std::cout << (*begin).first << " " << (*begin).second << std::endl;
      mergeSort<Iterator, Sequence>(mid, end);
      merge<Iterator, Sequence>(begin, mid, end);
  }
}

template <typename Sequence>
void PmergeMe::insertOrdered(Sequence& container, int value) {
  typename Sequence::iterator it = std::lower_bound(container.begin(), container.end(), value);
  container.insert(it, value);
}

#endif
