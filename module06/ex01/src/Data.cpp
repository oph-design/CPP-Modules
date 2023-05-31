/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:07:08 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/31 15:38:44 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : _node(NULL) {}

Data::Data(std::string newContent) :_node(newNode(newContent)) {}

Data::Data(const Data& rhs) {
  t_node* iterate = rhs._node;

  if (rhs._node == NULL)
    _node = NULL;
  while (iterate != NULL) {
    this->insert(iterate->content);
    iterate = iterate->next;
  }
}

Data::~Data(void) {
  this->deleteList();
}

Data&  Data::operator=(const Data& rhs) {
  t_node* iterate = rhs._node;

  this->deleteList();
  if (rhs._node == NULL)
    return (_node = NULL, *this);
  while (iterate != NULL) {
    this->insert(iterate->content);
    iterate = iterate->next;
  }
  return (*this);
}

t_node* Data::newNode(std::string content) {
  t_node *res = new t_node;

  res->content = content;
  res->next = NULL;
  return (res);
}

void Data::deleteList(void) {
  t_node* iterate = _node;
  t_node* tmp;

  while (iterate) {
    tmp = iterate;
    iterate = iterate->next;
    delete tmp;
  }
  _node = NULL;
}

void Data::insert(std::string content) {
  if (_node == NULL) {
    _node = newNode(content);
    return ;
  }
  this->getLastNode()->next = newNode(content);
}

t_node* Data::getLastNode(void) const {
  t_node* iterator = _node;

  while (iterator && iterator->next != NULL)
    iterator = iterator->next;
  return (iterator);
}

t_node* Data::getFirstNode(void) const {
  return (_node);
}

std::ostream& operator<<(std::ostream& out, const Data& rhs) {
  int i = 0;
  t_node *iterate = rhs.getFirstNode();

  out << "---------------\n";
  while (iterate != NULL) {
    out << "Node " << i++ << ": " << iterate->content << "\n";
    iterate = iterate->next;
  }
  out << "---------------" << std::endl;
  return (out);
}

