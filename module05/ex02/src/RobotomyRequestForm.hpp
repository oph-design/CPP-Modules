/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:08:44 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/27 17:04:05 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
    std::string _target;

 public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(const RobotomyRequestForm &rhs);
    RobotomyRequestForm(std::string newTarget);
    ~RobotomyRequestForm(void);
    RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs);
    std::string getTarget(void) const;
    void setTarget(std::string newTarget);
    void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& rhs);

#endif
