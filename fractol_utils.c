/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elite <elite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:49:37 by elite             #+#    #+#             */
/*   Updated: 2024/07/06 02:02:41 by elite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double a, double b, double i)
{
	return ((b - a) * (i - 0) / (HEIGH - 0) + a);
}

void	my_mlx_pixel_put(t_params *par, int i, int j, int color)
{
	char	*temp;

	temp = par->address + j * par->size_line + (i * par->bits_per_pixel / 8);
	*(int *)temp = color;
}

void	handle_color_if_out_of_disk(t_params *par, int i, int j)
{
	if (par->display == 5)
		my_mlx_pixel_put(par, i, j, 0xd44219);
	else if (par->display == 10)
		my_mlx_pixel_put(par, i, j, 0xd94214);
	else if (par->display == 15)
		my_mlx_pixel_put(par, i, j, 0xfa481b);
	else if (par->display == 20)
		my_mlx_pixel_put(par, i, j, 0xdb500f);
	else if (par->display == 25)
		my_mlx_pixel_put(par, i, j, 0xdb670f);
	else if (par->display == 30)
		my_mlx_pixel_put(par, i, j, 0xdb640f);
	else if (par->display == 40)
		my_mlx_pixel_put(par, i, j, 0xeb7907);
	else if (par->display == 100)
		my_mlx_pixel_put(par, i, j, 0xde9f18);
}

int	print_color(t_params *par, int i, int j)
{
	if (par->z1 * par->z1 + par->z2 * par->z2 <= 4)
	{
		my_mlx_pixel_put(par, i, j, 0x050505);
		return (0);
	}
	else
	{
		handle_color_if_out_of_disk(par, i, j);
		return (1);
	}
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
		{
			i++;
		}
		else
			break ;
	}
	return (str1[i] - str2[i]);
}
