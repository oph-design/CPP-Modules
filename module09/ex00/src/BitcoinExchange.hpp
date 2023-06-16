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
# include <string>
# include <map>
# include <fstream>
# include <sstream>

class BitcoinExchange {
 private:
  std::multimap<int, float> _content;
  std::multimap<int, float> _data;
  void calcAmount(std::pair<int, float> set);
  static std::multimap<int, float> convertData(void);
  static std::string formatDate(int date);
  static bool edgeTheCases(std::pair<int, float> set);

 public:
  BitcoinExchange(void);
  BitcoinExchange(std::string filename);
  BitcoinExchange(const BitcoinExchange& rhs);
  ~BitcoinExchange(void);
  BitcoinExchange& operator=(const BitcoinExchange& rhs);
  void calcBitcoinExchange(void);
  std::multimap<int, float> getContent(void) const;
};

// std::ostream& operator<<(std::ostream& out, const BitcoinExchange& rhs);

#endif
