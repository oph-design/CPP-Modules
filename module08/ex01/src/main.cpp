/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:33:23 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/12 10:18:59 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
  Span sp = Span(7);
  try {
    sp.longestSpan();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  sp.addNumber(6);
  sp.addNumber(5);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  Span test = Span(10000);
  test.addNumberPlusPlus();
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  std::cout << test.shortestSpan() << std::endl;
  std::cout << test.longestSpan() << std::endl;
  return 0;
}
