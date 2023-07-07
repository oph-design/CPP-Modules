/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:28:10 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/07 08:51:11 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <ctime>
# include <cstdlib>

bool operator<=(const std::pair<int, int> left,
  const std::pair<int, int> right);

template<typename T>
void swap(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}

template <typename Container>
clock_t initSortedPairs(char *argv[], int argc, Container& cont) {
  std::pair<int, int> current;
  clock_t start;

  start = clock();
  for (int i = 0; i < argc; ++i) {
    if (argv[i + 1]) {
      current.first = std::atoi(argv[i++]);
      current.second = std::atoi(argv[i]);
    } else
      continue;
    if (current.first < current.second)
      swap(current.first, current.second);
    cont.push_back(current);
  }
  return (clock() - start);
}

template <typename Iterator, typename Sequence>
void merge(Iterator begin, Iterator mid, Iterator end) {
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
void mergeSort(Iterator first, Iterator last) {
  if (std::distance(first, last) > 1) {
    Iterator mid = first;
    std::advance(mid, std::distance(first, last) / 2);
    mergeSort<Iterator, Sequence>(first, mid);
    mergeSort<Iterator, Sequence>(mid, last);
    merge<Iterator, Sequence>(first, mid, last);
  }
}

template <typename Container, typename Iterator>
void bnSort(Container& c, Iterator first, Iterator last, int val) {
  Iterator mid = first;

  std::advance(mid, std::distance(first, last) / 2);
  if (std::distance(first, last) == 1) {
    (*first > val) ? c.insert(first, val) : c.insert(first + 1, val);
    return;
  }
  (*mid > val) ? bnSort(c, first, mid, val) : bnSort(c, mid, last, val);
}

template <typename Container>
void insertIntoContainer(Container& vec, int value) {
  typename Container::iterator it = std::lower_bound(vec.begin(), vec.end(), value);
  vec.insert(it, value);
}

#endif
