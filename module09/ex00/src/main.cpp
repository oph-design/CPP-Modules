/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:04:14 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/16 10:58:48 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  try {
    BitcoinExchange BitcoinExchange(argv[argc - 1]);
    BitcoinExchange.calcBitcoinExchange();
  } catch (std:exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
