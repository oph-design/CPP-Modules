/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:18:18 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/01 08:06:49 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
  try {
    ScalarConverter::convert(std::string(argv[argc - 1]));
  } catch (std::exception&)  {
    std::cout << "overflow" << std::endl;
  }
}
