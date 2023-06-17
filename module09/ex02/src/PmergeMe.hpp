/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:07:57 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/17 16:00:02 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <ctime>
# include <cstdlib>

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
    void mergeAndInsertVec(void);
    void mergeAndInsertDq(void);

 private:
    pair_vec _vec;
    pair_dq _dq;
    int* _strag;
    template <typename Container>
    static void	sort_pairs(Container& pairs);
    template <typename Container>
    static void insertIntoContainer(Container& vec, int value);
};

std::ostream& operator<<(std::ostream& out, const PmergeMe& rhs);

# include "PmergeMe.tpp"

#endif
