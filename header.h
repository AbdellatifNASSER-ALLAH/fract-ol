/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:12:11 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/17 16:04:58 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <mlx.h>

#define HEIGHT 800
#define WIDTH 800

typedef struct	s_point {
	double	x;
	double	y;
}	t_point;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int	bpp;
	int	line_length;
	int	endian;
}	t_img;

typedef struct	s_fractal {
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	int	num_inter;
	double	escapce_value;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

// *** fractal functions ***
void	init_fractal(t_fractal *fractal);
void	render_fractal(t_fractal *fractal);

// *** check promot ***
int valid_promot(int ac, char **av);
#endif
