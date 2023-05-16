/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:50:39 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/16 16:09:33 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <string>

class Fixed
{
	private:
		int	_fixe;
		static const int	_fract;

	public:
		Fixed(void);
		Fixed(const Fixed &rhs);
		Fixed(int newFixe);
		~Fixed(void);
		Fixed& operator=(const Fixed &rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		void output(void);
};

#endif
