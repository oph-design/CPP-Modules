/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:51:12 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/20 16:04:42 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include <iostream>
# include <string>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 private:
    std::string _name;

 public:
    DiamondTrap(void);
    DiamondTrap(const DiamondTrap &rhs);
    DiamondTrap(std::string newName);
    ~DiamondTrap(void);
    DiamondTrap& operator=(const DiamondTrap &rhs);
    std::string getName(void) const;
    void setName(std::string newName);

    void whoAmI(void);
    using ScavTrap::attack;
};

std::ostream& operator<<(std::ostream& out, const DiamondTrap& rhs);

#endif
