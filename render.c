/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:43:39 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/18 03:02:21 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_point	choose(t_point z, t_fractal *fractal)
{
	if (ft_strcmp(fractal->name, "mandelbort"))
		return (z);
	z.x = fractal->julia_x;
	z.y = fractal->julia_y;
	return (z);
}

static void	my_put_pixel(int x, int y, t_img *img, int color)
{
	char	*offset;

	offset = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)offset = color;
}

static void	do_pixel(int x, int y, t_fractal *fractal)
{
	t_point	z;
	t_point	c;
	int		color;
	int		i;

	z.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	c = choose(z, fractal);
	i = 0;
	while (i < fractal->num_iter)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = ft_degree_color(fractal, i);
			my_put_pixel(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_put_pixel(x, y, &fractal->img, BLAK);
}

void	render_fractal(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			do_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
