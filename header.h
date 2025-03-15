/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:12:11 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/15 17:22:55 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <mlx.h>

#include <stdio.h>


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

typedef struct	s_point
{
	int	x;
	int y;
}	t_point;

void	ft_pixel_put(t_data *data, int x, int y, int color);

#endif
