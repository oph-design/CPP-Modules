/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:07:57 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/06 18:47:48 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <sstream>
# include <ctime>
# include <cstdlib>
# include "Utils.hpp"

class PmergeMe {
 public:
    typedef std::deque< std::pair<int, int> > pair_dq;
    typedef std::vector< std::pair<int, int> > pair_vec;
    PmergeMe(void);
    PmergeMe(const PmergeMe &rhs);
    PmergeMe(int argc, char **argv);
    ~PmergeMe(void);
    PmergeMe& operator=(const PmergeMe &rhs);
    void mergeAndInsertVec(void);
    void mergeAndInsertDq(void);

 private:
    pair_vec _vec;
    pair_dq _dq;
    std::pair<clock_t, clock_t> _begins;
    int* _strag;
};

bool operator<=(const std::pair<int, int> left,
                const std::pair<int, int> right);

#endif
