/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:13:56 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/18 17:50:48 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	render_next(t_fractal *fractal)
{
	render_fractal(fractal);
	return (0);
}

int	close_handler(t_fractal *fractal)
{
	clean_up(fractal, 0);
	return (0);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		clean_up(fractal, 0);
	if (keycode == LEFT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	if (keycode == RIGHT)
		fractal->shift_x += (0.5 * fractal->zoom);
	if (keycode == UP)
		fractal->shift_y += (0.5 * fractal->zoom);
	if (keycode == DOWN)
		fractal->shift_y -= (0.5 * fractal->zoom);
	if (keycode == PLUS)
		fractal->theme += 2;
	if (keycode == MINUS)
		fractal->theme -= 2;
	if (keycode == RUN)
		fractal->julia_move = 1;
	if (keycode == STOP)
		fractal->julia_move = 0;
	if (keycode == RESET)
		init_data(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	x = x + y - y;
	if (button == 5)
		fractal->zoom *= 0.9;
	if (button == 4)
		fractal->zoom *= 1.1;
	if (button == 1)
		fractal->num_iter += 10;
	if (button == 3)
		fractal->num_iter -= 10;
	return (0);
}

int	julia_handler(int x, int y, t_fractal *fractal)
{
	if (ft_strcmp(fractal->name, "julia") && fractal->julia_move)
	{
		fractal->julia_x = (map(x, -2, 2, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia_y = (map(y, 2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
	}
	return (0);
}
