/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:57:18 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/01 20:47:49 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>

template <class T>
class Array {
 private:
  T* _values;
  unsigned int _size;

 public:
  Array(void) : _values(NULL), _size(0) {}

  Array(unsigned int n): _values(new T[n]), _size(n) {}

  Array(const Array<T> & rhs)
    : _values(new T[rhs._size]), _size(rhs._size) {
    for (unsigned int i = 0; i < rhs._size; ++i)
      _values[i] = rhs._values[i];
  }

  Array<T>& operator=(const Array<T> & rhs) {
    delete [] _values;
    _values = new T[rhs._size];
    for (unsigned int i = 0; i < rhs._size; ++i)
      _values[i] = rhs._values[i];
    _size = rhs._size;
    return (*this);
  }

  T& operator[](unsigned index) {
    if (index >= _size)
      throw std::exception();
    return (_values[index]);
  }

  unsigned int size(void) const {
    return (_size);
  }
};

#endif
