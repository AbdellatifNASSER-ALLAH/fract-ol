/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:12:11 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/17 21:16:48 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 700
# define WIDTH 700

// *** Colors ***
# define WHITE 0xFFFFFF
# define BLAK 0x000000

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	int		num_iter;
	double	escape_value;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fractal;

// *** fractal functions ***
void		init_fractal(t_fractal *fractal);
void		render_fractal(t_fractal *fractal);

// *** events ***
int			close_handler(t_fractal *fractal);

// *** utils ***
int			ft_strcmp(const char *s1, const char *s2);
int			valid_promot(int ac, char **av);
double		to_double(const char *s, double intger, double fractional);
void		clean_up(t_fractal *fractal);

// *** math utils ***
double		map(double unscaled_num, double new_min, double new_max,
				double old_max);
t_point		sum_complex(t_point z1, t_point z2);
t_point		square_complex(t_point z);

#endif
