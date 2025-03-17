/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:12:11 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/17 03:34:35 by abdnasse         ###   ########.fr       */
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
}	t_fractal;

// *** check promot ***
int valid_promot(int ac, char **av);
#endif
