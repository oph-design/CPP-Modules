/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:04:14 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/13 16:34:07 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Balance.hpp"

int main(int argc, char *argv[]) {
  Balance balance(argv[argc - 1]);
  std::cout << balance;
  return (0);
}
