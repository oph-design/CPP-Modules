/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:45:27 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/26 18:49:01 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <string>

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
 public:
    Intern(void);
    Intern(const Intern &rhs);
    ~Intern(void);
    Intern& operator=(const Intern &rhs);
    AForm* makeForm(std::string name, std::string target);
};

std::ostream& operator<<(std::ostream& out, const Intern& rhs);

#endif
