/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:29:12 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/20 15:01:04 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>
# include <string>

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap{
 public:
    FragTrap(void);
    FragTrap(std::string newName);
    FragTrap(const FragTrap &rhs);
    ~FragTrap(void);
    FragTrap& operator=(const FragTrap &rhs);

    void highFiveGuys(void);
};

std::ostream& operator<<(std::ostream& out, const FragTrap& rhs);

#endif
