/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:28:50 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/31 22:56:31 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template<typename T>
void swap(T& a, T& b) {
  T c = a;
  a = b;
  b = c;
}

template<typename T>
const T& min(const T& a, const T& b) {
  if (a < b)
    return (a);
  if (b < a)
    return (b);
  return (b);
}

template<typename T>
const T& max(const T& a, const T& b) {
  if (a > b)
    return (a);
  if (b < a)
    return (b);
  return (b);
}

#endif
