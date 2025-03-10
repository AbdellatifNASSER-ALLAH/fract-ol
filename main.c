/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:11:17 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/10 17:00:11 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

typedef struct	s_point
{
	int	x;
	int y;
}	t_point;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
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
		my_mlx_pixel_put(img, center.x, center.y + i, 0x00ff0000);
		my_mlx_pixel_put(img, center.x, center.y - i, 0x00ff0000);
		my_mlx_pixel_put(img, center.x + i, center.y, 0x00ff0000);
		my_mlx_pixel_put(img, center.x - i, center.y, 0x00ff0000);
		i++;
	}
	p.x = center.x - 20;
	p.y = center.y - 20;
	i = 0;
	while (i < 40)
	{	
		j = 0;
		while(j < 40)
		{
			my_mlx_pixel_put(img, p.x + j, p.y + i, 0x0000a500);
			j++;
		}
		i++;
	}
}

int	main()
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "eh eh");
	img.img = mlx_new_image(mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	draw_something(&img, 400, 400);

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}
