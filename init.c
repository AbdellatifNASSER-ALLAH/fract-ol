/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:08:45 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/15 20:58:29 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();	
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, TITLE);
	vars->d_img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->d_img.addr = mlx_get_data_addr(vars->d_img.img, &vars->d_img.bpp,
		&vars->d_img.line_length, &vars->d_img.endian);
}
