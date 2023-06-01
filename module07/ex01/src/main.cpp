/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:02:08 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/01 20:53:10 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main (void)
{
  char array1[3] = {'H', 'W', 'O'};
  iter(array1, 3, &::xToOut);

  std::string array2[3] = {"Hey", "Hello", "World"};
  iter(array2, 3, &::xToOut);

  int array3[3] = {4, 5, 6};
  iter(array3, 3, &::xToOut);
}
