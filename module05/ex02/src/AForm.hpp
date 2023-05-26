/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:23:36 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/26 16:04:23 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_H
# define AForm_H

# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
 protected:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;

 public:
    AForm(void);
    AForm(const AForm &rhs);
    AForm(std::string newName, int newSignGrade, int newExecGrade);
    virtual ~AForm(void);

    AForm& operator=(const AForm &rhs);
    std::string getName(void) const;
    bool getIsSigned(void) const;
    int getSignGrade(void) const;
    int getExecGrade(void) const;
    void setIsSigned(bool newIsSigned);
    void beSigned(Bureaucrat& signee);
    virtual void execute(Bureaucrat const & executor) = 0;

    class GradeTooHighException : public std::exception {
     public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
     public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& rhs);

#endif
