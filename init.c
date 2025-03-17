/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:03:00 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/17 17:55:25 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	malloc_error(t_fractal *fractal)
{
	if (fractal->img.img)
		mlx_destroy_image(fractal->mlx, fractal->img.img);
	if (fractal->win)
		mlx_destroy_window(fractal->mlx, fractal->win);
	if (fractal->mlx)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	perror("Malloc error");
	exit(1);
}

static void	init_data(t_fractal *fractal)
{
	fractal->num_iter = 42;
	fractal->escape_value = 4;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
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
	//TODO:events hook
}
