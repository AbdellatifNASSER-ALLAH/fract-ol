/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:11:17 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/17 15:01:26 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (!valid_promot(ac, av))
		return (1);
	fractal.name = av[1];
	init_fractal(&fractal);//TODO
	render_fractal(&fractal);//TODO
	mlx_loop(fraclat.mlx);//TODO
	return (0);
}
