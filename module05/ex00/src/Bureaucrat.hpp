/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:07:51 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/25 17:57:55 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string>

class Bureaucrat {
 private:
    const std::string _name;
    int _grade;

 public:
    Bureaucrat(void);
    Bureaucrat(const Bureaucrat &rhs);
    Bureaucrat(std::string newName, int newGrade);
    ~Bureaucrat(void);
    Bureaucrat& operator=(const Bureaucrat &rhs);

    std::string getName(void) const;
    int getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);

    class GradeTooHighException : public std::exception {
     public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
     public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs);

#endif
