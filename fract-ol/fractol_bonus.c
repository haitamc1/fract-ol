/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:33:30 by hchahid           #+#    #+#             */
/*   Updated: 2022/04/26 13:37:24 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	my_mlx_pixel_put(t_p *p, int x, int y, int color)
{
	char	*dst;

	dst = p->addr + (y * p->line_length + x * (p->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

double	map(int x, double max, double min)
{
	return (x * (max - min) / (double) WIDTH + min);
}

void	draw(t_p *p)
{
	double	cr;
	double	ci;
	int		n;
	int		i;
	int		j;

	i = 0;
	while (i < 600)
	{
		j = 0;
		cr = map(i, p->r_or + p->scope, p->r_or - p->scope);
		while (j < 600)
		{
			ci = map(j, p->i_or + p->scope, p->i_or - p->scope);
			n = wich_set(p, cr, ci);
			if (n < p->max_it)
				color(p, i, j, n);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}

void	initial(t_p *p)
{
	p->max_it = 255;
	p->x = 0;
	p->y = 0.8;
	p->color = 1;
	p->scope = 2;
	p->r_or = 0;
	p->i_or = 0;
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "fractol");
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->addr = mlx_get_data_addr(p->img, &p->bits_per_pixel,
			&p->line_length, &p->endian);
}

int	main(int ac, char **av)
{
	t_p	p;

	if (ac == 2)
	{
		p.set = ft_atoi(av[1]);
		if (p.set >= 1 && p.set <= 8)
		{
			guides();
			initial(&p);
			draw(&p);
			mlx_hook(p.win, 17, 0, &cross, &p);
			mlx_hook(p.win, 2, 1L << 0, &key, &p);
			mlx_hook(p.win, 6, 0, &mouse_move, &p);
			mlx_mouse_hook(p.win, *mouse_hook, &p);
			mlx_loop(p.mlx);
		}
		write(1, "\n\033[0;31m INVALID ARGUMENT\n", 29);
	}
	write(1, "\n\033[0;36m SELECT A SET\n\n", 26);
	sets();
	return (0);
}
