/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:45:13 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/16 18:24:16 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char *argv[]) {
  try {
    RPN calc(argv[argc - 1]);
    std::cout << calc << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
