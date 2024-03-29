/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:10:15 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/07 14:52:01 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <limits>

bool check_zero(char *str) {
  size_t i = 0;

  while (str[i] && str[i] == 48)
    i++;
  if (i && i == std::strlen(str))
    return (true);
  return (false);
}


bool check_input(char *argv[]) {
  double num;

  for (size_t i = 1; argv[i]; ++i) {
    if (check_zero(argv[i]))
      continue ;
    std::istringstream(std::string(argv[i])) >> num;
    if (num == 0 || !argv[i][0] || num < INT_MIN || num > INT_MAX)
      return (false);
  }
  return (true);
}

int main(int argc, char *argv[]) {
  if (argc <= 2 || !check_input(argv))
    return (std::cerr << "bad input" << std::endl, 1);
  PmergeMe sortation(argc - 1, ++argv);
  sortation.mergeAndInsertVec();
  sortation.mergeAndInsertDq();
  return (0);
}
