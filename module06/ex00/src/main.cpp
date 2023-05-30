/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:18:18 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/30 19:36:20 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
  try {
  ScalarConverter::convert(std::string(argv[argc - 1]));
  } catch (std::exception& e) {
    std::cout << "overflow" << std::endl;
  }
}
