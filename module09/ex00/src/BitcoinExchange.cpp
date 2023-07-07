/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:16:21 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/07 19:03:19 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _data(convertData()) {}

BitcoinExchange::BitcoinExchange(std::string filename) : _data(convertData()) {
  _file.open(filename.c_str());
  if (!_file.is_open())
    throw std::runtime_error("Error: could not open file");
}

std::map<int, float> BitcoinExchange::convertData(void) {
  struct tm dummy;
  std::ifstream file("data.csv");
  std::map<int, float> res;
  std::string input;
  int date;
  float value;

  while(std::getline(file, input)) {
    if (input.empty() || !input.compare("date,exchange_rate"))
      continue;
    if (input.find(",") == input.npos)
      throw std::runtime_error("database format error");
    input.erase(std::remove(input.begin(), input.end(), '-'), input.end());
    date = std::atoi(input.substr(0, input.find(",")).c_str());
    if (!strptime(formatDate(date).c_str(), "%Y-%m-%d", &dummy))
      throw std::runtime_error("wrong date format");
    value = std::atof(input.substr(input.find(",") + 1).c_str());
    res.insert(std::pair<int, float>(date, value));
  }
  return (res);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {
  *this = rhs;
}

BitcoinExchange::~BitcoinExchange(void) {
  _file.close();
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
  this->_data = rhs._data;
  return (*this);
}

std::string BitcoinExchange::formatDate(int date) {
  std::ostringstream raw;
  raw << date;
  std::string res = raw.str();

  if (res.length() < 7)
    return (res);
  res.insert(4, "-");
  res.insert(7, "-");
  return (res);
}

bool BitcoinExchange::edgeTheCases(int date, float amount) {
  struct tm dummy;

  if (!strptime(formatDate(date).c_str(), "%Y-%m-%d", &dummy)) {
    std::cout << "Error: bad input => " << formatDate(date) << "\n";
    return (false);
  }
  if (amount < 0) {
    std::cout << "Error: not a positive number\n";
    return (false);
  }
  if (amount > 1000) {
    std::cout << "Error: too large a number\n";
    return (false);
  }
  return (true);
}

void BitcoinExchange::calcAmount(int date, float amount) {
  if (!edgeTheCases(date, amount))
    return;
  std::map<int, float>::iterator it = _data.begin();
  while (it != _data.end() && it->first < date)
    it++;
  if (it->first < date)
    it--;
  std::cout << formatDate(date) << " => " << amount;
  std::cout << " " << (amount * it->second) << "\n";
}

void BitcoinExchange::calcBitcoinExchange(void) {
  int date;
  float amount;
  std::string input;
  std::string helper;

  while (std::getline(_file, input)) {
    if (input.empty() || !input.compare("date | value"))
      continue;
    if (input.find("|") == input.npos) {
      input.erase(std::remove(input.begin(), input.end(), '-'), input.end());
      this->calcAmount(std::atoi(input.c_str()), 0);
      continue;
    }
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    helper = input.substr(0, input.find("|"));
    helper.erase(std::remove(helper.begin(), helper.end(), '-'), helper.end());
    date = std::atoi(helper.c_str());
    amount = std::atof(input.substr(input.find("|") + 1).c_str());
    this->calcAmount(date, amount);
  }
}
