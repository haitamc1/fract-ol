/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:03:40 by hchahid           #+#    #+#             */
/*   Updated: 2022/04/26 13:41:17 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	wich_set(t_p *p, double cr, double ci)
{
	if (p->set == 1)
		return (mandelbrot(cr, ci, p->max_it));
	if (p->set == 2)
		return (mandelbrot3(cr, ci, p->max_it));
	if (p->set == 3)
		return (mandelbrot4(cr, ci, p->max_it));
	if (p->set == 4)
		return (julia(cr, ci, p));
	if (p->set == 5)
		return (julia3(cr, ci, p));
	if (p->set == 6)
		return (julia4(cr, ci, p));
	if (p->set == 7)
		return (burning_ship(cr, ci, p->max_it));
	if (p->set == 8)
		return (feigenbaum(cr, ci, p->max_it));
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	r;
	int	s;

	r = 0;
	s = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r += str[i] - '0';
		i++;
	}
	return (r * s);
}
