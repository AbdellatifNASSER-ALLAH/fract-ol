/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:17:49 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/18 00:40:41 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	is_double(const char *s)
{
	if (!*s || !s)
		return (0);
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
		s++;
	while (*s && (*s >= '0' && *s <= '9'))
		s++;
	if (*s == '.' && (*(s - 1) >= '0' && *(s - 1) <= '9') && (*(s + 1) >= '0'
			&& *(s + 1) <= '9'))
		s++;
	while (*s && (*s >= '0' && *s <= '9'))
		s++;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (!*s)
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 == *s2);
}

int	valid_promot(int ac, char **av)
{
	if (ac == 2 && ft_strcmp(av[1], "mandelbort"))
		return (1);
	if (ac == 4 && ft_strcmp(av[1], "julia") && is_double(av[2])
		&& is_double(av[3]))
		return (1);
	write(2, "Invalid argument                       \n", 40);
	write(2, " ------------ Usage ------------------ \n", 40);
	write(2, "|  ./fractol mandelbort               |\n", 40);
	write(2, "|            Or:                      |\n", 40);
	write(2, "| ./fractol julia <real> <i>          |\n", 40);
	write(2, " ------------------------------------- \n", 40);
	return (0);
}

double	to_double(const char *s, double intger, double fractional)
{
	double	factor;
	int		sign;

	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s && *s != '.')
		intger = (intger * 10) + (*s++ - 48);
	if (*s == '.')
		s++;
	factor = 1;
	while (*s)
	{
		factor *= 10;
		fractional = fractional + (*s++ - 48) / factor;
	}
	return ((intger + fractional) * sign);
}

void	clean_up(t_fractal *fractal, int err)
{
	if (fractal->img.img)
		mlx_destroy_image(fractal->mlx, fractal->img.img);
	if (fractal->win)
		mlx_destroy_window(fractal->mlx, fractal->win);
	if (fractal->mlx)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	exit(err);
}
