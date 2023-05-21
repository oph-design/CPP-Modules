/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:57:42 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/21 20:18:29 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_H
# define A_MATERIA_H

# include <iostream>
# include <string>

# include "ICharacter.hpp"

class AMateria
{
 protected:
    std::string _type;

 public:
    AMateria(void);
    AMateria(std::string const & type);
    AMateria(const AMateria &rhs);
    AMateria& operator=(const AMateria & rhs);
    virtual ~AMateria(void);
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
