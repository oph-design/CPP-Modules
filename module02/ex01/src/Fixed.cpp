/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:50:31 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/17 18:47:29 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fract = 8;

Fixed::Fixed(void)
	: _fixe(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed::Fixed(int newFixe)
	: _fixe(newFixe << _fract)
{

}

Fixed::Fixed(float newFixe)
	: _fixe(roundf(newFixe * (1 << _fract)))
{

}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixe = rhs.getRawBits();
	return (*this);
}

int Fixed::toInt(void) const
{
	return (_fixe >> 8);
}

float Fixed::toFloat(void) const
{
	return ((float)(_fixe / roundf(1 << _fract)));
}


int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixe);
}

void Fixed::setRawBits(int const raw)
{
	_fixe = raw;
}

void Fixed::output(void)
{
	std::cout << "fixe : " << _fixe << std::endl;
	std::cout << "fract : " << _fract << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Fixed &rhs)
{
	out << rhs.toFloat();
	return (out);
}
