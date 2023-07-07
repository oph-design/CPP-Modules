/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:28:10 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/07 11:34:15 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include <ctime>
# include <cstdlib>
# include <cmath>
# include <algorithm>

bool operator<=(const std::pair<int, int> left,
  const std::pair<int, int> right);

template<typename T>
void swap(T& a, T& b);

template <typename Sequence>
clock_t initSortedPairs(char *argv[], int argc, Sequence& cont);

template <typename Iterator, typename Sequence>
void merge(Iterator begin, Iterator mid, Iterator end);

template <typename Iterator, typename Sequence>
void mergeSort(Iterator first, Iterator last);

template <typename Container>
void jakobFactory(Container& cont, size_t size);

template <typename Container, typename Iterator>
void bnSort(Container& c, Iterator first, Iterator last, int val);

template <typename Cont, typename Seq>
void insertionSort(Cont& res, Cont jakob, Seq pairs);

# include "Algorithm.tpp"

#endif
