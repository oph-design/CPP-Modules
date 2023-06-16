/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:04:14 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/16 14:08:54 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool check_char(char c) {
  return (!std::isdigit(c) && c != '|' && c != '.' && c != ' ' && c != '-');
}

bool check_input(std::string filename) {
  std::ifstream file(filename);
  std::string input;

  if (!file.is_open())
    throw std::runtime_error("Error: could not open file");
  while (std::getline(file, input)) {
    if (input.at(0) == '\n' || !input.compare("date | value"))
      continue;
    for (int i = 0, i < input.length(), ++i)
      if (check_char(input.at(i)))
        throw std::runtime_error("Error: bad input");
    if (input.substr(input.find("|")).find("|") != input.npos)
      throw std::runtime_error("Error: bad input");
    if (input.substr(input.find(".")).find(".") != input.npos)
      throw std::runtime_error("Error: bad input");
  }
  return (true);
}

int main(int argc, char *argv[]) {
  try {
    check_input(argv[argc - 1]);
    BitcoinExchange BitcoinExchange(argv[argc - 1]);
    BitcoinExchange.calcBitcoinExchange();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
