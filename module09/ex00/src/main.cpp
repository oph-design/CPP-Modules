/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:04:14 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/09 12:41:42 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2)
    return (std::cerr << "Error: number of inputs" << std::endl, 1);
  try {
    BitcoinExchange BitcoinExchange(argv[1]);
    BitcoinExchange.calcBitcoinExchange();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
