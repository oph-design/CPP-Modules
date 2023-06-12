/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:38:09 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/12 10:38:11 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <string>
# include <vector>
# include <climits>
# include <algorithm>
# include <ctime>
# include <cstdlib>

class Span {
 private:
    std::vector<int> _vec;
    unsigned int _size;

 public:
    Span(void);
    Span(const Span &rhs);
    Span(unsigned int size);
    ~Span(void);
    Span& operator=(const Span &rhs);
    std::vector<int> getVec(void) const;
    void setVec(std::vector<int> newVec);
    void addNumber(int value);
    void addNumberPlusPlus();
    int shortestSpan();
    int longestSpan();
};

#endif
