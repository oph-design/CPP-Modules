/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:18:34 by oheinzel          #+#    #+#             */
/*   Updated: 2023/06/08 21:47:03 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

# include <algorithm>
# include <vector>
# include <array>
# include <deque>
# include <forward_list>
# include <list>
# include <stack>
# include <queue>

template<typename T>
typename T::container_type& getUnderlyingContainer(T& containerAdapter) {
    struct ContainerHolder : T {
        static typename T::container_type& getContainer(T& adapter) {
            return adapter.*&ContainerHolder::c;
        }
    };
    return ContainerHolder::getContainer(containerAdapter);
}

template<typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator it;
  it = std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw std::runtime_error("value not found");
  return (it);
}

template<typename T>
typename T::container_type::iterator easyfind(T& container, int value) {
    return easyfind(getUnderlyingContainer(container), value);
}

#endif
