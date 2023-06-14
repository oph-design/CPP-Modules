/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Balance.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:11:22 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/14 14:55:47 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BALANCE_H
# define BALANCE_H

# include <iostream>
# include <string>
# include <map>
# include <fstream>

class Balance {
 private:
  std::multimap<int, float> _content;
  float* _amounts;

 public:
  Balance(void);
  Balance(std::string filename);
  Balance(const Balance& rhs);
  ~Balance(void);
  Balance& operator=(const Balance& rhs);
  std::multimap<int, float> getContent(void) const;
};

std::ostream& operator<<(std::ostream& out, const Balance& rhs);

#endif
