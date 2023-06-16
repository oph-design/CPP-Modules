/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:07:57 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/17 01:02:03 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <string>
# include <vector>
# include <deque>

template<typename T>
void swap(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}

class PmergeMe {
 public:
    typedef std::deque< std::pair<int, int> > pair_dq;
    typedef std::vector< std::pair<int, int> > pair_vec;
    PmergeMe(void);
    PmergeMe(const PmergeMe &rhs);
    PmergeMe(int argc, char **argv);
    ~PmergeMe(void);
    PmergeMe& operator=(const PmergeMe &rhs);
    pair_vec getVec(void) const;
    pair_dq getDq(void) const;
    void setVec(pair_vec newVec);
    void setDq(pair_dq newDq);
    void mergeAndInsert(void);

 private:
    pair_vec _vec;
    pair_dq _dq;
    template <typename Iterator, typename Sequence>
    static void mergeSort(Iterator begin, Iterator end);
    template <typename Iterator, typename Sequence>
    static void merge(Iterator begin, Iterator mid, Iterator end);
    template <typename Sequence>
    static void insertOrdered(Sequence& container, int value);
};

std::ostream& operator<<(std::ostream& out, const PmergeMe& rhs);

# include "PmergeMe.tpp"

#endif
