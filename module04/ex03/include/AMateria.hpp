/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:57:42 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 16:38:31 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_H
# define A_MATERIA_H

# include <iostream>
# include <string>

# include "ICharacter.hpp"

class AMateria {
 protected:
    std::string _type;

 public:
    AMateria(void);
    AMateria(std::string const & type);
    AMateria(const AMateria &rhs);
    AMateria& operator=(const AMateria & rhs);
    virtual ~AMateria(void);
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
