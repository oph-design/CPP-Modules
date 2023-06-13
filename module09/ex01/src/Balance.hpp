/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Balance.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:11:22 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/13 16:18:35 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BALANCE_H
# define BALANCE_H

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>

class Balance {
 private:
  std::map<std::string, int> _content;

 public:
  Balance(void);
  Balance(std::string filename);
  Balance(const Balance& rhs);
  Balance& operator=(const Balance& rhs);
  std::map<std::string, int> getContent(void) const;
};

std::ostream& operator<<(std::ostream& out, const Balance& rhs);

#endif
