/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:29:31 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 16:33:27 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
}

Brain::Brain(const Brain& rhs) {
  *this = rhs;
}

Brain::~Brain(void) {
}

Brain&  Brain::operator=(const Brain& rhs) {
  unsigned int i = 0;

  while (i < 100) {
    this->_ideas[i] = rhs.getIdeaByIndex(i);
    i++;
  }
  return (*this);
}

std::string Brain::getIdeaByIndex(unsigned int index) const {
  return (_ideas[index]);
}

void Brain::setIdeaByIndex(std::string newIdea, unsigned int index) {
  _ideas[index] = newIdea;
}

std::ostream& operator<<(std::ostream& out, const Brain& rhs) {
  unsigned int i = 0;

  out << "---------------\n";
  while (i < 100) {
    out << "Idea " << i + 1  << ": " << rhs.getIdeaByIndex(i) << "\n";
    i++;
  }
  out << "---------------" << std::endl;
  return (out);
}

