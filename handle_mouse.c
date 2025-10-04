/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elite <elite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:49:45 by elite             #+#    #+#             */
/*   Updated: 2024/07/06 01:59:12 by elite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_or_julia(t_params *par, int i, int j)
{
	if (par->check == 1)
		mandelbrot(par, i, j);
	if (par->check == 2)
		julia(par, i, j);
}

int	zoom(t_params *par)
{
	if (par->click[0] == 1)
		par->facteur -= 0.05;
	else if (par->click[1] == 1)
		par->facteur += 0.05;
	return (0);
}

int	move(int button, int x, int y, t_params *par)
{
	(void)x;
	(void)y;
	if (button == 5)
		par->click[0] = 1;
	else if (button == 4)
		par->click[1] = 1;
	return (0);
}

int	mouse_hundler(t_params *par)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < HEIGH)
	{
		i = 0;
		while (i < WIDTH)
		{
			mandelbrot_or_julia(par, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(par->connection, par->window, par->img, 0, 0);
	zoom(par);
	par->click[0] = 0;
	par->click[1] = 0;
	return (0);
}
