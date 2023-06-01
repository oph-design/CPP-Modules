/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:34:11 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/01 14:46:47 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>

template<typename T>
void iter(T array[], size_t len, void (*func)(T input)) {
  for (size_t i = 0; i < len; ++i) {
    func(array[i]);
  }
}

template<typename T>
void xToOut(T x) {
  std::cout << x << std::endl;
}

#endif
