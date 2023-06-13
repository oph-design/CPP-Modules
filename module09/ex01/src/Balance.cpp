/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Balance.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:16:21 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/13 16:45:44 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Balance.hpp"

Balance::Balance(void) : _content(std::map<std::string, int>()) {
}

Balance::Balance(std::string filename) {
  this->_content = std::map<std::string, int>();
  std::ifstream file(filename);
  std::string input;
  double value;

  std::getline(file, input);
  while (input.length() == 1 || !input.compare("date | value"))
    std::getline(file, input);
  while (input.length()) {
    std::stringstream ss(input.substr(input.find("|") + 1, input.length()));
    ss >> value;
    std::cout << value << std::endl;
    _content[input.substr(0, input.find("|") - 1)] = value;
    std::getline(file, input);
    std::cout << input << std::endl;
  }
}

Balance::Balance(const Balance& rhs) {
  *this = rhs;
}

Balance& Balance::operator=(const Balance& rhs) {
  this->_content = rhs._content;
  return (*this);
}

std::map<std::string, int> Balance::getContent(void) const {
  return (this->_content);
}

std::ostream& operator<<(std::ostream& out, const Balance& rhs) {
  std::map<std::string, int> content = rhs.getContent();
  for (std::map<std::string, int>::iterator it = content.begin(); it != content.end(); ++it)
    out << it->first << " | " << it->second << std::endl;
  return (out);
}
