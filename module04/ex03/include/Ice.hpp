/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:42:00 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/21 20:42:16 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include <iostream>
# include <string>

# include "AMateria.hpp"

class Ice : public AMateria {
 public:
    Ice(void);
    Ice(const Ice &rhs);
    ~Ice(void);
    Ice& operator=(const Ice &rhs);
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
