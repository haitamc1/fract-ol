/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_sets_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:05:29 by hchahid           #+#    #+#             */
/*   Updated: 2022/04/26 13:40:58 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	feigenbaum(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	i = 0;
	zr = 0;
	zi = 0;
	while (i < max_iter && (zr * zr) + (zi * zi) <= 4)
	{
		tmp = (zr * zr) - (zi * zi) + (cr * cr * cr)
			- (3 * cr * ci * ci) - 1.401155;
		zi = (2 * zr * zi) + (3 * cr * cr * ci) - (ci * ci * ci);
		zr = tmp;
		i++;
	}
	return (i);
}

int	burning_ship(double cr, double ci, int max_iter)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	i = 0;
	zr = 0;
	zi = 0;
	while (i < max_iter && (zr * zr) + (zi * zi) <= 4)
	{
		tmp = (zr * zr) - (zi * zi) + cr;
		zi = fabs((2 * zr * zi)) + ci;
		zr = tmp;
		i++;
	}
	return (i);
}
