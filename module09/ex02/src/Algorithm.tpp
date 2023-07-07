/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:18:25 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/07 11:33:53 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_T
# define ALGO_T

# include "Algorithm.hpp"

template<typename T>
void swap(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}

template <typename Sequence>
clock_t initSortedPairs(char *argv[], int argc, Sequence& cont) {
  std::pair<int, int> current;
  clock_t start;

  start = clock();
  for (int i = 0; i < argc; ++i) {
    if (argv[i + 1]) {
      current.first = std::atoi(argv[i++]);
      current.second = std::atoi(argv[i]);
    } else break;
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

template <typename Container>
void jakobFactory(Container& cont, size_t size) {
  int j = 0;
  int current = 0;
  int prev = 0;
  int tmp = 0;

  cont.push_back(current);
  for (size_t i = 0; i < size; ++i) {
    prev = current;
    current = pow(2, j++) - current;
    tmp = current - 1;
    if (current != prev)
      cont.push_back(current);
    if (prev == current)
      continue;
    while (i < size && tmp != prev) {
      cont.push_back(tmp--);
      i++;
    }
  }
}

template <typename Container, typename Iterator>
void bnSort(Container& c, Iterator first, Iterator last, int val) {
  Iterator mid = first;

  std::advance(mid, std::distance(first, last) / 2);
  if (std::distance(first, last) <= 1) {
    (*first > val) ? c.insert(first, val) : c.insert(first + 1, val);
    return;
  }
  (*mid > val) ? bnSort(c, first, mid, val) : bnSort(c, mid, last, val);
}

template <typename Cont, typename Seq>
void insertionSort(Cont& res, Cont jakob, Seq pairs) {
  int toInsert;
  typename Cont::iterator bound;

  for (typename Seq::iterator it = pairs.begin(); it < pairs.end(); ++it)
    res.push_back(it->first);
  for (typename Cont::iterator it = jakob.begin(); it < jakob.end(); ++it) {
    toInsert = pairs[*it].second;
    bound = find(res.begin(), res.end(), pairs[*it].first);
    bnSort<Cont, typename Cont::iterator>(res, res.begin(), bound, toInsert);
  }
}

#endif
