/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:58:10 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/25 18:13:37 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat bob("Bob", 1);
    std::cout << bob;
    Bureaucrat bob2(bob);
    std::cout << bob2;
    Bureaucrat tyler("Tyler", 150);
    std::cout << tyler;
    tyler = bob;
    bob.incrementGrade();
    std::cout << tyler;
  } catch (std::exception e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
