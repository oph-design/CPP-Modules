/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:54:15 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/31 22:14:14 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <iomanip>
# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer {
 private:
    Serializer(void);
    Serializer(const Serializer& rhs);
    Serializer& operator=(const Serializer& rhs);
    ~Serializer(void);

 public:
    static uintptr_t serialize(Data *ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
