/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:00:13 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/30 19:19:29 by oheinzel         ###   ########.fr       */
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

typedef struct s_values {
  char character;
  int integer;
  float fpoint;
  double dpoint;
} t_values;

class ScalarConverter {
 private:
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter& rhs);
  ScalarConverter& operator=(const ScalarConverter &rhs);
  ~ScalarConverter(void);

  static void convChar(std::string str, t_values& val);
  static void convInt(std::string str, t_values& val);
  static void convDouble(std::string str, t_values& val, int isFloat);
  static void printVals(t_values& vals);
  static int checkStr(std::string str);
  static int getType(std::string str);

 public:
  static void convert(std::string str);
};

#endif
