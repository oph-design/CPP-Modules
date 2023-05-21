/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:25:59 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/21 11:30:30 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>
# include <string>

class Brain {
 private:
    std::string _ideas[100];

 public:
    Brain(void);
    Brain(const Brain &rhs);
    Brain(std::string newIdeas);
    ~Brain(void);
    Brain& operator=(const Brain &rhs);
    std::string getIdeaByIndex(unsigned int index) const;
    void setIdeaByIndex(std::string newIdea, unsigned int index);
};

std::ostream& operator<<(std::ostream& out, const Brain& rhs);

#endif
