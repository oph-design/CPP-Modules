/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:20:54 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/31 21:37:07 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"
# include "Data.hpp"

int main(void) {
  Data* list = new Data("node alpha");
  Data* test;
  uintptr_t raw;

  list->insert("node beta");
  std::cout << *list;
  std::cout << "original ptr:\t" << list << std::endl;
  raw = Serializer::serialize(list);
  std::cout << "raw ptr:\t0x" << std::hex << raw << std::endl;
  test = Serializer::deserialize(raw);
  std::cout << "test ptr:\t" << test << std::endl;
  std::cout << *test;
  delete test;
}
