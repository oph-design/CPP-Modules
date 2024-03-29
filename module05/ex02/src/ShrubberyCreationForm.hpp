/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:11:03 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/26 17:55:29 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include <fstream>
# include <string>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
 private:
    std::string _target;

 public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
    ShrubberyCreationForm(std::string newTarget);
    ~ShrubberyCreationForm(void);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
    std::string getTarget(void) const;
    void setTarget(std::string newTarget);
    void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& rhs);

#endif
