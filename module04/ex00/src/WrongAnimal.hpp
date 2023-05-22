/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 09:53:03 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 14:23:25 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

# include <iostream>
# include <string>

class WrongAnimal {
 protected:
    std::string _type;

 public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal &rhs);
    WrongAnimal(std::string newType);
    ~WrongAnimal(void);
    WrongAnimal& operator=(const WrongAnimal &rhs);
    std::string getType(void) const;
    void setType(std::string newType);
    void makeSound(void) const;
};

std::ostream& operator<<(std::ostream& out, const WrongAnimal& rhs);

#endif
