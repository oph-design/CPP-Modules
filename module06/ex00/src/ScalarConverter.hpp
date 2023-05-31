/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:00:13 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/31 16:40:00 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_H
# define SCALAR_CONVERTER_H

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <math.h>
# include <climits>
# include <cfloat>

# ifndef PREC
#  define PREC 6
# endif

class ScalarConverter {
 private:
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter& rhs);
  ScalarConverter& operator=(const ScalarConverter &rhs);
  ~ScalarConverter(void);

  static void convChar(std::string str);
  static void convInt(std::string str);
  static void convDouble(std::string str, int isFloat);
  static bool handlePseudos(std::string str);
  static bool checkDoubleOverflow(std::string str, double check);
  static bool checkStr(std::string str);
  static int getType(std::string str);

 public:
  static void convert(std::string str);
};

#endif
