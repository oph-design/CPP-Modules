/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:16:21 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/16 17:23:47 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
  : _content(std::multimap<int, float>()), _data(convertData()) {}

BitcoinExchange::BitcoinExchange(std::string filename) : _data(convertData()) {
  _content = std::multimap<int, float>();
  std::ifstream file(filename);
  std::string input;
  std::string helper;
  int date;
  float value;

  if (!file.is_open())
    throw std::runtime_error("Error: could not open file");
  while (std::getline(file, input)) {
    if (input.at(0) == '\n' || !input.compare("date | value"))
      continue;
    if (input.find("|") == input.npos) {
      _content.insert(std::pair<int, float>(std::atoi(input.c_str()), 0));
      continue;
    }
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    helper = input.substr(0, input.find("|"));
    helper.erase(std::remove(helper.begin(), helper.end(), '-'), helper.end());
    date = std::atoi(helper.c_str());
    value = std::stod(input.substr(input.find("|") + 1));
    _content.insert(std::pair<int, float>(date, value));
  }
  file.close();
}

std::multimap<int, float> BitcoinExchange::convertData(void) {
  std::ifstream file("data.csv");
  std::multimap<int, float> res;
  std::string input;
  int date;
  float value;

  while(std::getline(file, input)) {
   if (!input.compare("date,exchange_rate"))
       continue;
   input.erase(std::remove(input.begin(), input.end(), '-'), input.end());
   date = std::atoi(input.substr(0, input.find(",")).c_str());
   value = std::stof(input.substr(input.find(",") + 1));
   res.insert(std::pair<int, float>(date, value));
  }
  return (res);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {
  *this = rhs;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
  this->_content = rhs._content;
  this->_data = rhs._data;
  return (*this);
}

std::multimap<int, float> BitcoinExchange::getContent(void) const {
  return (this->_content);
}

std::string BitcoinExchange::formatDate(int date) {
  // std::ostringstream raw(date);
  std::string res = std::to_string(date);

  //raw >> res;
  res.insert(4, "-");
  res.insert(7, "-");
  return (res);
}

bool BitcoinExchange::edgeTheCases(std::pair<int, float> set) {
  if (set.first % 100 > 31 || (set.first / 100) % 100 > 12
      || set.first % 100 == 0 ||  (set.first / 100) % 100 == 0) {
    std::cout << "Error: bad input => " << formatDate(set.first) << "\n";
    return (false);
  }
  if (set.second < 0) {
    std::cout << "Error: not a positive number\n";
    return (false);
  }
  if (set.second > 1000) {
    std::cout << "Error: too large a number\n";
    return (false);
  }
  return (true);
}

void BitcoinExchange::calcAmount(std::pair<int, float> set) {
  if (!edgeTheCases(set))
    return;
  std::multimap<int, float>::iterator it = _data.begin();
  while (it != _data.end()) {
    if (it->first < set.first) {j
      it++; continue;
    }
    if (it->first == set.first)
      break;
    it--;
    break;
  }
  std::cout << formatDate(set.first) << " => " << set.second;
  std::cout << " " << (set.second * it->second) << "\n";
}

void BitcoinExchange::calcBitcoinExchange(void) {
  for (std::multimap<int, float>::iterator it = _content.begin();
      it != _content.end(); ++it) {
    this->calcAmount(*it);
  }
}

// std::ostream& operator<<(std::ostream& out, const BitcoinExchange& rhs) {
//   std::multimap<int, float> content = rhs.getContent();
//   for (std::map<int, float>::iterator it = content.begin();
//         it != content.end(); ++it)
//     out << it->first << " | " << it->second << std::endl;
//   return (out);
// }
