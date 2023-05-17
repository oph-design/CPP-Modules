/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oheinzel <oheinzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:08:51 by oheinzel          #+#    #+#             */
/*   Updated: 2023/05/17 13:34:06 by oheinzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed a1;
	Fixed a2;
	Fixed d;

	a1 = ((a.getX() - c.getX()) * (point.getY() - c.getY())) -
		((a.getY() - c.getY()) * (point.getX() - c.getX()));
	a2 = ((b.getX() - a.getX()) * (point.getY() - a.getY())) -
		((b.getY() - a.getY()) * (point.getX() - a.getX()));

	if ((a1 < 0) != (a2 < 0) && a1 != 0 && a2 != 0)
		return (false);
	d = ((c.getX() - b.getX()) * (point.getY() - b.getY())) -
		((c.getY() - b.getY()) * (point.getX() - b.getX()));
	return (d == 0 || (d < 0) == (a1 + a2 <= 0));
}
