/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:16:21 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/16 10:53:51 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
  : _content(std::multimap<int, double>()), _data(convertData()){}

BitcoinExchange::BitcoinExchange(std::string filename) : _data(convertData()){
  this->_content = std::multimap<int, double>();
  std::ifstream file(filename);
  std::string input;
  std::string helper;
  int date;
  double value;

  if (!file.is_open())
    throw std::runtime_error("Error: could not open file");
  while (std::getline(file, input)) {
    if (input.find("|") == input.npos || !input.compare("date | value"))
      continue;
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    helper = input.substr(0, input.find("|"));
    helper.erase(std::remove(helper.begin(), helper.end(), '-'), helper.end());
    date = std::atoi(helper.c_str());
    value = std::stof(input.substr(input.find("|") + 1));
    this->_content.insert(std::pair<int, double>(date, value));
  }
  file.close();
}

std::multimap<int, double> BitcoinExchange::convertData(void) {
 std::ifstream file("data.csv");
 std::multimap<int, double> res;
 std::string input;
 int date;
 double value;

 while(std::getline(file, input)) {
  if (!input.compare("date,exchange_rate"))
      continue;
  input.erase(std::remove(input.begin(), input.end(), '-'), input.end());
  date = std::atoi(input.substr(0, input.find(",")).c_str());
  value = std::stof(input.substr(input.find(",") + 1));
  res.insert(std::pair<int, double>(date, value));
 }
 return (res);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {
  *this = rhs;
}

BitcoinExchange::~BitcoinExchange(void) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
  this->_content = rhs._content;
  this->_data = rhs._data;
  return (*this);
}

std::multimap<int, double> BitcoinExchange::getContent(void) const {
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

bool BitcoinExchange::edgeTheCases(std::pair<int, double> set) {
  if (set.first % 100 > 31 || (set.first / 100) % 100 > 12
      || set.first % 100 == 0 ||  (set.first / 100) % 100 == 0) {
    std::cout << "Error: bad input => " << formatDate(set.first) << "\n";
    return (false);
  }
  if (set.second < 0) {
    std::cout << "Error: not a positive number\n";
    return (false);
  }
  if (set.second > 2147483647) {
    std::cout << "Error: too large a number\n";
    return (false);
  }
  return (true);
}

void BitcoinExchange::calcAmount(std::pair<int, double> set) {
  if (!edgeTheCases(set))
    return;
  std::multimap<int, double>::iterator it = _data.begin();
  while (it != _data.end()) {
    if (it->first < set.first) {
      it++; continue;
    }
    if (it->first == set.first)
      break;
    if (set.first - (it->first - 1) < it->first - set.first)
      it--;
    break;
  }
  std::cout << formatDate(set.first) << " => " << set.second;
  std::cout << " " << (set.second * it->second) << "\n";
}

void BitcoinExchange::calcBitcoinExchange(void) {
  for (std::multimap<int, double>::iterator it = _content.begin();
      it != _content.end(); ++it) {
    this->calcAmount(*it);
  }
}

// std::ostream& operator<<(std::ostream& out, const BitcoinExchange& rhs) {
//   std::multimap<int, double> content = rhs.getContent();
//   for (std::map<int, double>::iterator it = content.begin();
//         it != content.end(); ++it)
//     out << it->first << " | " << it->second << std::endl;
//   return (out);
// }
