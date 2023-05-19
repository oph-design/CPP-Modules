/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:23:06 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/19 21:42:21 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include <string>

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 public:
    ScavTrap(void);
    ScavTrap(std::string newName);
    ScavTrap(const ScavTrap &rhs);
    ~ScavTrap(void);
    ScavTrap& operator=(const ScavTrap &rhs);

    void attack(const std::string& target);
    void guardGate(void);
};

std::ostream& operator<<(std::ostream& out, const ScavTrap& rhs);

#endif
