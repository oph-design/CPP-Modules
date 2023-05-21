/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:45:35 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/21 21:53:07 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include <iostream>
# include <string>

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
 private:
    AMateria* _templates[4];

 public:
    MateriaSource(void);
    MateriaSource(const MateriaSource &rhs);
    ~MateriaSource(void);
    MateriaSource& operator=(const MateriaSource &rhs);
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif
