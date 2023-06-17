/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:45:14 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/17 16:36:08 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

template <typename Container>
void	PmergeMe::sort_pairs(Container& pairs)
{
	for (typename Container::iterator it = (pairs.begin() + 1); it != pairs.end(); it++)
	{
		std::pair<int, int> val = *it;
		typename Container::iterator ite = (it - 1);
		while (ite >= pairs.begin() && val.first < ite->first)
			*(ite + 1) = *ite--;
		*(ite + 1) = val;
	}
}

template <typename Container>
void PmergeMe::insertIntoContainer(Container& vec, int value) {
    typename Container::iterator it = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(it, value);
}

#endif
