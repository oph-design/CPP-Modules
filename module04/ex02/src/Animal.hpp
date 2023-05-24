/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:53:03 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/24 10:24:05 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>

class Animal {
 protected:
    std::string _type;
    Animal(void);
    Animal(const Animal &rhs);
    Animal(std::string newType);
    virtual ~Animal(void);

 public:
    Animal& operator=(const Animal &rhs);
    std::string getType(void) const;
    void setType(std::string newType);
    virtual void makeSound(void) const = 0;
};

std::ostream& operator<<(std::ostream& out, const Animal& rhs);

#endif
