/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:52:46 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/12 10:31:05 by oheinzel         ###   ########.fr       */
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
  MutantStack<int>::iterator iter = std::find(a.begin(), a.end(), 12);
  std::cout << "iterator to 12:\t" << *iter << std::endl;
  std::cout << "a.top:\t\t" << a.top() << std::endl;
  a.pop();
  std::cout << "new a.top:\t" << a.top() << std::endl;
  std::cout << "a.empty:\t" << a.empty() << std::endl;
  std::cout << "a.size:\t\t" << a.size() << std::endl;
  MutantStack<int> b(a);
  std::cout << "b.top:\t\t" << b.top() << std::endl;
  b.pop();
  b.pop();
  a = b;
  std::cout << "a.top after assignement: " << a.top() << std::endl;
}
