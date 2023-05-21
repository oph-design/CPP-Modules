/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:14:16 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/21 21:18:36 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include <iostream>
# include <string>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {
 private:
    std::string _name;
    AMateria* _inventar[4];

 public:
    Character(void);
    Character(const Character &rhs);
    Character(std::string newName);
    ~Character(void);
    Character& operator=(const Character &rhs);
    std::string const & getName(void) const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
