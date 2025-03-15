/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:12:11 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/15 20:55:10 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <mlx.h>

#define HEIGHT 500
#define WIDTH 500
#define TITLE "Fract-ol"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bpp;
	int	line_length;
	int	endian;
}	t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	d_img;
}	t_vars;

void	init_vars(t_vars *vars);
void	ft_pixel_put(t_data *data, int x, int y, int color);

#endif
