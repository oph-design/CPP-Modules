/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:07:57 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/07 11:31:38 by oheinzel         ###   ########.fr       */
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

# include "Algorithm.hpp"

typedef std::deque< std::pair<int, int> > pair_dq;
typedef std::vector< std::pair<int, int> > pair_vec;
typedef std::vector<int> int_vec;
typedef std::deque<int> int_dq;

class PmergeMe {
 public:
    PmergeMe(int argc, char **argv);
    ~PmergeMe(void);
    void mergeAndInsertVec(void);
    void mergeAndInsertDq(void);

 private:
    PmergeMe(void);
    PmergeMe(const PmergeMe &rhs);
    PmergeMe& operator=(const PmergeMe &rhs);
    pair_vec _vec;
    pair_dq _dq;
    int* _strag;
    std::pair<clock_t, clock_t> _begins;
};

#endif
