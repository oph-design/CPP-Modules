/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:45:14 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/17 11:44:17 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

template <typename Iterator>
void PmergeMe::insertionSort(Iterator begin, Iterator end) {
    for (Iterator i = begin + 1; i != end; ++i) {
        int key = *i;
        Iterator j = i - 1;

        while (j >= begin && *j > key) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

template <typename Iterator, typename Container>
void PmergeMe::merge(Iterator begin, Iterator mid, Iterator end) {
    Container temp;
    Iterator i = begin, j = mid + 1;
    while (i <= mid && j <= end) {
        if (*i <= *j)
            temp.push_back(*i++);
        else
            temp.push_back(*j++);
    }
    while (i <= mid)
        temp.push_back(*i++);
    while (j <= end)
        temp.push_back(*j++);
    std::copy(temp.begin(), temp.end(), begin);
}

template <typename Iterator, typename Container>
void PmergeMe::mergeInsertionSort(Iterator begin, Iterator end) {
    if (std::distance(begin, end) <= 10) {
        insertionSort(begin, end);
    } else {
        Iterator mid = begin + std::distance(begin, end) / 2;
        mergeInsertionSort<Iterator, Container>(begin, mid);
        mergeInsertionSort<Iterator, Container>(mid + 1, end);
        merge<Iterator, Container>(begin, mid, end);
    }
}

// template <typename Container>
// Container PmergeMe::mergeInsertionSort(Container arr) {
//     mergeInsertionSort< typename Container<int>::iterator, Container >(arr.begin(), arr.end() - 1);
//     return arr;
// }

#endif
