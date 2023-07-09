/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:11:22 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/16 10:47:16 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_H
# define BitcoinExchange_H

# include <iostream>
# include <algorithm>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <cmath>
# include <ctime>

class BitcoinExchange {
 private:
  std::map<int, float> _data;
  std::ifstream _file;
  void calcAmount(std::string date, float amount);
  static std::map<int, float> convertData(void);
  static int dateToInt(std::string date);
  static bool checkInput(std::string date, float amount);

 public:
  BitcoinExchange(void);
  BitcoinExchange(std::string filename);
  BitcoinExchange(const BitcoinExchange& rhs);
  ~BitcoinExchange(void);
  BitcoinExchange& operator=(const BitcoinExchange& rhs);
  void calcBitcoinExchange(void);
};

#endif
