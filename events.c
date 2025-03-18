/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:13:56 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/18 03:24:00 by abdnasse         ###   ########.fr       */
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
		fractal->theme += 1;
	if (keycode == MINUS)
		fractal->theme -= 1;
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
