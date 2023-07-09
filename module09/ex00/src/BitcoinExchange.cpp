/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:16:21 by oheinzel          #+#    #+#             */
/*   Updated: 2023/07/09 12:39:11 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _data(convertData()) {}

BitcoinExchange::BitcoinExchange(std::string filename) : _data(convertData()) {
  _file.open(filename.c_str());
  if (!_file.is_open())
    throw std::runtime_error("Error: could not open file");
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

int BitcoinExchange::dateToInt(std::string date) {
  date.erase(std::remove(date.begin(), date.end(), '-'), date.end());
  return (std::atoi(date.c_str()));
}

std::map<int, float> BitcoinExchange::convertData(void) {
  struct tm dummy;
  std::ifstream file("data.csv");
  std::map<int, float> res;
  std::string input;
  std::string date;
  float value;

  while(std::getline(file, input)) {
    if (input.empty() || !input.compare("date,exchange_rate"))
      continue;
    if (input.find(",") == input.npos)
      throw std::runtime_error("database format error");
    date = input.substr(0, input.find(","));
    if (!strptime(date.c_str(), "%Y-%m-%d", &dummy)
      || date.substr(date.rfind("-"), date.length()).length() > 3)
      throw std::runtime_error("wrong date format");
    value = std::atof(input.substr(input.find(",") + 1).c_str());
    res.insert(std::pair<int, float>(dateToInt(date), value));
  }
  return (res);
}

bool BitcoinExchange::checkInput(std::string date, float amount) {
  struct tm dummy;

  if (!strptime(date.c_str(), "%Y-%m-%d", &dummy)
    || date.substr(date.rfind("-"), date.length()).length() > 3) {
    std::cout << "Error: bad input => " << date << "\n";
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

void BitcoinExchange::calcAmount(std::string date, float amount) {
  int date_val = dateToInt(date);
  std::map<int, float>::iterator it = _data.begin();

  if (!checkInput(date, amount))
    return;
  if (it->first > date_val) {
    std::cout << "Error: bad date => " << date << "\n";
    return ;
  }
  while (it != _data.end() && it->first < date_val)
    it++;
  if (it->first < date_val)
    it--;
  std::cout << date << " => " << amount;
  std::cout << " " << (amount * it->second) << "\n";
}

void BitcoinExchange::calcBitcoinExchange(void) {
  std::string date;
  float amount;
  std::string input;

  while (std::getline(_file, input)) {
    if (input.empty() || !input.compare("date | value"))
      continue;
    if (input.find("|") == input.npos) {
      this->calcAmount(input, 0);
      continue;
    }
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    date = input.substr(0, input.find("|"));
    amount = std::atof(input.substr(input.find("|") + 1).c_str());
    this->calcAmount(date, amount);
  }
}
