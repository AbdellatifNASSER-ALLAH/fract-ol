/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:16:59 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/18 03:40:05 by abdnasse         ###   ########.fr       */
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

int	ft_degree_color(t_fractal *fractal, int iter)
{
	if (fractal->theme == 0)
		return (0x00FFFF00 * iter + WHITE);
	if (fractal->theme == 1)
		return (0x00FF00FF * iter);
	iter += fractal->theme;
	if (iter % 2 != 0)
		return (255 * iter / 98 + 234567);
	return (255 * iter / fractal->num_iter + WHITE);
}
