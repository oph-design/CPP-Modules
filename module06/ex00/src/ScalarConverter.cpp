/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:32:04 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/30 19:18:12 by oheinzel         ###   ########.fr       */
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

void ScalarConverter::convChar(std::string str, t_values& val) {
  std::stringstream ss(str);
  std::stringstream sc(str);
  double check;

  sc >> check;
  if (check > INT_MAX || check< INT_MIN)
    throw std::exception();
  ss >> val.character;
  val.integer = static_cast<int>(val.character);
  val.fpoint = static_cast<float>(val.character);
  val.dpoint = static_cast<double>(val.character);
}

void ScalarConverter::convInt(std::string str, t_values& val) {
  std::stringstream ss(str);
  std::stringstream sc(str);
  double check;

  sc >> check;
  if (check > INT_MAX || check < INT_MIN)
    throw std::exception();
  ss >> val.integer;
  val.character = static_cast<char>(val.integer);
  val.fpoint = static_cast<float>(val.integer);
  val.dpoint = static_cast<double>(val.integer);
}

void ScalarConverter::convDouble(std::string str, t_values& val, int isFloat) {
  std::stringstream ss(str);
  std::stringstream sc(str);
  double c;

  sc >> c;
  if (isFloat && (c > FLT_MAX || c < FLT_MIN))
    throw std::exception();
  ss >> val.dpoint;
  val.integer = static_cast<int>(val.dpoint);
  val.fpoint = static_cast<float>(val.dpoint);
  val.character = static_cast<char>(val.dpoint);
}

void ScalarConverter::printVals(t_values& vals) {
  if (vals.character < 32 || vals.character > 126)
    std::cout << "char: not displayable" << std::endl;
  else
    std::cout << "char: " << vals.character << std::endl;
  std::cout << "int: " << vals.integer << std::endl;
  if (fmodf(vals.fpoint, 1.0) == 0)
    std::cout << std::fixed << std::setprecision(1);
  else
    std::cout << std::setprecision(PREC);
  std::cout << "float: " << vals.fpoint << "f" << std::endl;
  std::cout << "double: " << vals.dpoint << std::endl;

}

void ScalarConverter::convert(std::string str) {
  t_values vals;
  int isFloat = 0;

  if (str.find("f") != str.npos) {
    str = str.substr(0, str.find("f"));
    isFloat = 1;
  }
  switch (getType(str))
  {
    case 1:
      convChar(str, vals); break;
    case 2:
      convDouble(str, vals, isFloat); break;
    case 3:
      convInt(str, vals); break;
    default:
      std::cerr << "not convertable" << std::endl; return;
  }
  printVals(vals);
}
