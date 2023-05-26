/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:23:36 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/26 11:16:35 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
 private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;

 public:
    Form(void);
    Form(const Form &rhs);
    Form(std::string newName, int newSignGrade, int newExecGrade);
    ~Form(void);

    Form& operator=(const Form &rhs);
    std::string getName(void) const;
    bool getIsSigned(void) const;
    int getSignGrade(void) const;
    int getExecGrade(void) const;
    void setIsSigned(bool newIsSigned);
    void beSigned(Bureaucrat& signee);

    class GradeTooHighException : public std::exception {
     public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
     public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Form& rhs);

#endif
