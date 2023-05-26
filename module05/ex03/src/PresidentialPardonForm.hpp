/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:31:15 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/26 17:54:50 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <iostream>
# include <string>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm{
 private:
    std::string _target;

 public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(const PresidentialPardonForm &rhs);
    PresidentialPardonForm(std::string newTarget);
    ~PresidentialPardonForm(void);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs);
    std::string getTarget(void) const;
    void setTarget(std::string newTarget);
    void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& rhs);

#endif
