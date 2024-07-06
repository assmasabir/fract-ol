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
	return ((b - a) * (i - 0) / (1000 - 0) + a);
}

void	my_mlx_pixel_put(t_params *par, int i, int j, int color)
{
	char	*temp;

	temp = par->address + j * par->size_line + (i * par->bits_per_pixel / 8);
	*(int *)temp = color;
}

void	handle_color_if_out_of_disk(t_params *par, int i, int j)
{
	if (par->display == 10)
		my_mlx_pixel_put(par, i, j, 0xb57d47);
	else if (par->display == 20)
		my_mlx_pixel_put(par, i, j, 0xb57d47);
	else if (par->display == 30)
		my_mlx_pixel_put(par, i, j, 0xab7037);
	else if (par->display == 40)
		my_mlx_pixel_put(par, i, j, 0xab6826);
	else if (par->display == 50)
		my_mlx_pixel_put(par, i, j, 0xb56618);
	else if (par->display == 70)
		my_mlx_pixel_put(par, i, j, 0xdb8025);
	else if (par->display == 90)
		my_mlx_pixel_put(par, i, j, 0xdb8030);
	else if (par->display == 100)
		my_mlx_pixel_put(par, i, j, 0xdb8050);
}

int	print_color(t_params *par, int i, int j)
{
	if (par->z1 * par->z1 + par->z2 * par->z2 <= 4)
	{
		my_mlx_pixel_put(par, i, j, 0x383532);
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
