/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:32:04 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/31 09:37:50 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

int ScalarConverter::checkStr(std::string str) {
  bool hasPoint = false;
  size_t len = str.length();

  if (len == 0 || len > 308)
    return (0);
  if (len == 1)
    return (1);
  for (size_t i = 0; i < len; i++) {
    if (str.at(i) == '.' && !hasPoint) {
      hasPoint = true;
      continue;
    }
    if (!std::isdigit(str.at(i)))
      return (0);
  }
  return (1);
}

int ScalarConverter::getType(std::string str) {
  if (!checkStr(str))
    return (0);
  if (str.length() == 1)
    return (1);
  if (str.find(".") != str.npos)
    return (2);
  return (3);
}

void ScalarConverter::convChar(std::string str) {
  std::stringstream ss(str);
  std::stringstream sc(str);
  double check;
  char value;

  sc >> check;
  if (check > INT_MAX || check < INT_MIN)
    throw std::exception();
  ss >> value;
  std::cout << "char: ";
  if (value < 32 || value > 126)
    std::cout << "not displayable\n";
  else
    std::cout << static_cast<char>(value) << "\n";
  std::cout << "int: " << static_cast<int>(value) << "\n";
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float: " << static_cast<float>(value) << "f\n";
  std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convInt(std::string str) {
  std::stringstream ss(str);
  std::stringstream sc(str);
  double check;
  int value;

  sc >> check;
  if (check > INT_MAX || check < INT_MIN)
    throw std::exception();
  ss >> value;
  std::cout << "char: ";
  if (value < 32 || value > 126)
    std::cout << "not displayable\n";
  else
    std::cout << static_cast<char>(value) << "\n";
  std::cout << "int: " << value << "\n";
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float: " << static_cast<float>(value) << "f\n";
  std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convDouble(std::string str, int isFloat) {
  std::stringstream ss(str);
  std::stringstream sc(str);
  double value;
  double check;

  sc >> check;
  if (isFloat && (check > FLT_MAX || check < FLT_MIN))
    throw std::exception();
  ss >> value;
  std::cout << "char: ";
  if (value < 32 || value > 126)
    std::cout << "not displayable\n";
  else
    std::cout << static_cast<char>(value) << "\n";
  std::cout << "int: ";
  if (value > INT_MAX || value < INT_MIN)
    std::cout << "impossible\n";
  else
    std::cout << static_cast<int>(value) << "\n";
  if (fmodf(static_cast<float>(value), 1.0) == 0)
    std::cout << std::fixed << std::setprecision(1);
  else
    std::cout << std::setprecision(PREC);
  std::cout << "float: " << static_cast<float>(value) << "f\n";
  std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(std::string str) {
  int isFloat = 0;

  if (str.find("f") != str.npos) {
    str = str.substr(0, str.find("f"));
    isFloat = 1;
  }
  switch (getType(str))
  {
    case 1:
      convChar(str); break;
    case 2:
      convDouble(str, isFloat); break;
    case 3:
      convInt(str); break;
    default:
      std::cerr << "not convertable" << std::endl;
  }
}
