/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:32:20 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/22 17:07:26 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_H
# define WRONG_CAT_H

# include <iostream>
# include <string>

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
    WrongCat(void);
    WrongCat(const WrongCat &rhs);
    ~WrongCat(void);
    WrongCat& operator=(const WrongCat &rhs);
    void makeSound(void) const;
};

std::ostream& operator<<(std::ostream& out, const WrongCat& rhs);

#endif
