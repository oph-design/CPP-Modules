/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:02:02 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/21 11:40:45 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include <iostream>
# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal{
 private:
    Brain *_brain;

 public:
    Cat(void);
    Cat(const Cat &rhs);
    ~Cat(void);
    Cat& operator=(const Cat &rhs);
    void makeSound(void) const;
};

std::ostream& operator<<(std::ostream& out, const Cat& rhs);

#endif
