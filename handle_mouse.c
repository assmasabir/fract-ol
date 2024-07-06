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

int	mouse_hundler(int button, int x, int y, t_params *par)
{
	int	i;
	int	j;

	(void)x;
	(void)y;
	i = 0;
	j = 0;
	if (button == 4)
		par->facteur *= 0.95;
	else if (button == 5)
		par->facteur *= 1.1;
	while (j < 1000)
	{
		i = 0;
		while (i < 1000)
		{
			mandelbrot(par, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(par->connection, par->window, par->img, 0, 0);
	return (0);
}
