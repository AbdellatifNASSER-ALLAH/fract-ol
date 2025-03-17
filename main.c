/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:11:17 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/17 20:20:03 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (!valid_promot(ac, av))
		return (1);
	fractal.name = av[1];
	if (ft_strcmp(av[1], "julia"))
	{
		fractal.julia_x = to_double(av[2], 0, 0);
		fractal.julia_y = to_double(av[3], 0, 0);
	}
	init_fractal(&fractal);
	render_fractal(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
