/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:45:49 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/16 18:23:15 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <string>
# include <stack>
# include <sstream>

class RPN {
 private:
    std::stack<int> _nums;
    int calcNext(char c);

 public:
    RPN(void);
    RPN(const RPN &rhs);
    RPN(std::string input);
    ~RPN(void);
    RPN& operator=(const RPN &rhs);
    std::stack<int> getNums(void) const;
    void setNums(std::stack<int> newNums);
};

std::ostream& operator<<(std::ostream& out, const RPN& rhs);

#endif
