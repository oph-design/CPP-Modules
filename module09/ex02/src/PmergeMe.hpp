/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:07:57 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/17 11:39:04 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <string>
# include <vector>
# include <deque>

class PmergeMe {
 public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &rhs);
    PmergeMe(int argc, char **argv);
    ~PmergeMe(void);
    PmergeMe& operator=(const PmergeMe &rhs);
    std::vector<int> getVec(void) const;
    std::deque<int> getDq(void) const;
    void setVec(std::vector<int> newVec);
    void setDq(std::deque<int> newDq);
    void mergeAndInsert(void);

 private:
    std::vector<int> _vec;
    std::deque<int> _dq;
    template <typename Iterator>
    void insertionSort(Iterator begin, Iterator end);
    template <typename Iterator, typename Container>
    void merge(Iterator begin, Iterator mid, Iterator end);
    template <typename Iterator, typename Container>
    void mergeInsertionSort(Iterator begin, Iterator end);
    // template <typename Container>
    // Container mergeInsertionSort(Container arr);
};



std::ostream& operator<<(std::ostream& out, const PmergeMe& rhs);

# include "PmergeMe.tpp"

#endif
