/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:11:17 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/14 23:10:40 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_something(t_data *img, int height, int width)
{
	t_point	center;
	t_point	p;
	int	i;
	int	j;

	center.x = height / 2;
	center.y = width / 2;
	i = 0;
	while (i < height / 2 - 10)
	{	
		ft_pixel_put(img, center.x, center.y + i, 0x00ff0000);
		ft_pixel_put(img, center.x, center.y - i, 0x00ff0000);
		ft_pixel_put(img, center.x + i, center.y, 0x00ff0000);
		ft_pixel_put(img, center.x - i, center.y, 0x00ff0000);
		i++;
	}
	p.x = center.x - 50;
	p.y = center.y - 50;
	i = 0;
	while (i < 100)
	{	
		j = 0;
		while(j < 100)
		{
			ft_pixel_put(img, p.x + j, p.y + i, 0x0000a500);
			j++;
		}
		i++;
	}
}

int	main()
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 400, 400, "eh eh");
	img.img = mlx_new_image(vars.mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	draw_something(&img, 400, 400);

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
