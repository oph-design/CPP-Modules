/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:45:13 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/07 15:02:06 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char *argv[]) {
  if (argc != 2 || argv[1][0] == 0)
    return (std::cerr << "Error" << std::endl, 1);
  try {
    RPN calc(argv[1]);
    std::cout << calc << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
