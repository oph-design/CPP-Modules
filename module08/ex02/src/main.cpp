/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:52:46 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/08 22:14:18 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <algorithm>

int main(void) {
  MutantStack<int> a;

  a.push(10);
  a.push(11);
  a.push(12);
  a.push(13);
  a.push(14);
  std::cout << a.top() << std::endl;
  MutantStack<int>::iterator iter = std::find(a.begin(), a.end(), 12);
  std::cout << *iter << std::endl;
}
