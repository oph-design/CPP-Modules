/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:34:11 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/06 11:22:30 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>

template<typename T, typename V>
void iter(T* array, size_t len, V func) {
  if (array == NULL || func == NULL)
    return ;
  for (size_t i = 0; i < len; ++i) {
    func(array[i]);
  }
}

#endif
