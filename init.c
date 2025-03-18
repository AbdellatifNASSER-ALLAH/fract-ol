/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:03:00 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/18 17:49:27 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	malloc_error(t_fractal *fractal)
{
	perror("Malloc error");
	clean_up(fractal, 1);
}

static void	events_hook(t_fractal *fractal)
{
	mlx_hook(fractal->win, 17, 1L << 17, close_handler, fractal);
	mlx_hook(fractal->win, 2, 1L << 0, key_handler, fractal);
	mlx_hook(fractal->win, 4, 1L << 2, mouse_handler, fractal);
	mlx_hook(fractal->win, 6, 1L << 6, julia_handler, fractal);
}

void	init_data(t_fractal *fractal)
{
	fractal->num_iter = 42;
	fractal->escape_value = 4;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->theme = 55;
	fractal->julia_move = 0;
}

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		malloc_error(fractal);
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
	if (!fractal->win)
		malloc_error(fractal);
	fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img.img)
		malloc_error(fractal);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp,
			&fractal->img.line_length, &fractal->img.endian);
	init_data(fractal);
	events_hook(fractal);
}
