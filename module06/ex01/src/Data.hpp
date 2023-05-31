/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:08:06 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/31 15:03:59 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <iostream>
# include <string>

typedef struct s_node {
  std::string content;
  struct s_node* next;
} t_node;

class Data {
 private:
    t_node* _node;
    static t_node* newNode(std::string content);

 public:
    Data(void);
    Data(const Data& rhs);
    Data(std::string newContent);
    ~Data(void);
    Data& operator=(const Data& rhs);
    t_node* getFirstNode(void) const;
    t_node* getLastNode(void) const;
    void deleteList(void);
    void insert(std::string content);
};

std::ostream& operator<<(std::ostream& out, const Data& rhs);

#endif
