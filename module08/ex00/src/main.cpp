/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:55:05 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/08 15:12:55 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>

int main(void) {
  try {
    std::cout << "\033[1mvector:\033[0m" << std::endl;
    std::vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
    std::cout << *easyfind(vect, 30) << std::endl;
    std::cout << *easyfind(vect, 40) << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "\033[1marray:\033[0m" << std::endl;
    std::array<int, 3> arr;
    arr.fill(30);
    std::cout << *easyfind(arr, 30) << std::endl;
    std::cout << *easyfind(arr, 40) << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "\033[1mdeque:\033[0m" << std::endl;
    std::deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    std::cout << *easyfind(dq, 30) << std::endl;
    std::cout << *easyfind(dq, 40) << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "\033[1mforward_list:\033[0m" << std::endl;
    std::forward_list<int> forl;
    forl.push_front(10);
    forl.push_front(20);
    forl.push_front(30);
    std::cout << *easyfind(forl, 30) << std::endl;
    std::cout << *easyfind(forl, 40) << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "\033[1mlist:\033[0m" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    std::cout << *easyfind(lst, 30) << std::endl;
    std::cout << *easyfind(lst, 40) << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "\033[1mstack:\033[0m" << std::endl;
    std::stack<int> stck;
    stck.push(10);
    stck.push(20);
    stck.push(30);
    std::cout << *easyfind(stck, 30) << std::endl;
    std::cout << *easyfind(stck, 40) << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "\033[1mqueue:\033[0m" << std::endl;
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    std::cout << *easyfind(q, 30) << std::endl;
    std::cout << *easyfind(q, 40) << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
