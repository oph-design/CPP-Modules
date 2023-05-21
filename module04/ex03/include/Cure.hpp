/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:44:06 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/21 20:44:09 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include <iostream>
# include <string>

# include "AMateria.hpp"

class Cure : public AMateria {
 public:
    Cure(void);
    Cure(const Cure &rhs);
    ~Cure(void);
    Cure& operator=(const Cure &rhs);
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
