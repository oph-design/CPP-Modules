/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:10:01 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/08 22:14:07 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  typedef typename std::stack<T>::container_type::iterator iterator;
  MutantStack(void) : std::stack<T>() {}
  //MutantStack(C& container) :  std::stack<T>(container) {}
  MutantStack(const MutantStack& rhs) : std::stack<T>(rhs) {}
  ~MutantStack(void) {}
  MutantStack& operator=(const MutantStack& rhs) {
    std::stack<T>::operator=(rhs);
    return (*this);
  }
  iterator begin() {
    return (this->c.begin());
  }
  iterator end() {
    return (this->c.end());
  }
};

#endif
