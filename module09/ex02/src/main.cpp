/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:10:15 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/28 11:01:59 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>

bool check_input(char *argv[]) {
  int num;

  for (size_t i = 1; argv[i]; ++i) {
    if (std::strlen(argv[i]) == 1 && argv[i][0] == 48)
      continue ;
    std::istringstream(std::string(argv[i])) >> num;
    if (num == 0)
      return (false);
  }
  return (true);
}

int main(int argc, char *argv[]) {
  if (argc <= 1 || !check_input(argv))
    return (std::cerr << "wrong input" << std::endl, 1);
  PmergeMe sortation(argc - 1, ++argv);
  sortation.mergeAndInsertVec();
  sortation.mergeAndInsertDq();
  return (0);
}
