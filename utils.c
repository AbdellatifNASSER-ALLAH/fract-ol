/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:17:49 by abdnasse          #+#    #+#             */
/*   Updated: 2025/03/17 14:52:19 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_strcmp(const char *s1, const char *s2)
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
	if (ac == 4 && ft_strcmp(av[1], "julia"))
		return (1);
	write(2, "Invalid argument                       \n", 40);
	write(2, " ------------ Usage ------------------ \n", 40);
	write(2, "|  ./fractol mandelbort               |\n", 40);
	write(2, "|            Or:                      |\n", 40);
	write(2, "| ./fractol julia <real> <i>          |\n", 40);
	write(2, " ------------------------------------- \n", 40);
	return (0);
}
