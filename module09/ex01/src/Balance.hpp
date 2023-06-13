/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Balance.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:11:22 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/13 11:27:33 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BALANCE_H
# define BALANCE_H

# include <iostream>
# include <string>
# include <map>

class Balance {
 private:
  std::map<std::string, int> map;

 public:
  Balance(void);
  Balance(std::string filename);
  Balance(const Balance& rhs);
  Balance& operator=(const Balance& rhs);
};

#endif
