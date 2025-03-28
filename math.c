/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:16:59 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/18 16:54:59 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

t_point	sum_complex(t_point z1, t_point z2)
{
	t_point	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_point	square_complex(t_point z)
{
	t_point	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_degree_color(t_fractal *fractal, int iter)
{
	int		r;
	int		g;
	int		b;
	double	ratio;

	if (iter == fractal->num_iter)
		return (create_trgb(0, 0, 0, 0));
	ratio = (double)iter / fractal->theme;
	r = (int)(9 * (1 - ratio) * ratio * ratio * ratio * 255);
	g = (int)(15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255);
	b = (int)(8.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255);
	return (create_trgb(0, r, g, b));
}
