/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Balance.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:16:21 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/14 14:55:16 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Balance.hpp"

Balance::Balance(void) : _content(std::multimap<int, float>()), _amounts(NULL) {
}

Balance::Balance(std::string filename) {
  this->_content = std::multimap<int, float>();
  this->_amounts = NULL;
  std::ifstream file(filename);
  std::string input;
  int date;
  float value;

  while (std::getline(file, input)) {
    if (input.find("|") == input.npos || !input.compare("date | value"))
      continue;
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    input.erase(std::remove(input.begin(), input.end(), '-'), input.end());
    date = std::atoi(input.substr(0, input.find("|")).c_str());
    value = std::stof(input.substr(input.find("|") + 1));
    this->_content.insert(std::pair<int, float>(date, value));
  }
  this->_amounts = new float[_content.size()];
  file.close();
}

Balance::Balance(const Balance& rhs) {
  this->_amounts = NULL;
  *this = rhs;
}

Balance::~Balance(void) {
  delete [] this->_amounts;
}

Balance& Balance::operator=(const Balance& rhs) {
  delete [] this->_amounts;
  this->_content = rhs._content;
  this->_amounts = new float[this->_content.size()];
  for (size_t i = 0; i < this->_content.size(); ++i)
    this->_amounts[i] = rhs._amounts[i];
  return (*this);
}

std::multimap<int, float> Balance::getContent(void) const {
  return (this->_content);
}

std::ostream& operator<<(std::ostream& out, const Balance& rhs) {
  std::multimap<int, float> content = rhs.getContent();
  for (std::map<int, float>::iterator it = content.begin();
        it != content.end(); ++it)
    out << it->first << " | " << it->second << std::endl;
  return (out);
}
