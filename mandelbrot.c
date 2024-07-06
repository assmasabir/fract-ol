/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elite <elite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:49:51 by elite             #+#    #+#             */
/*   Updated: 2024/07/06 12:41:49 by elite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	somme(double *img, double *reel, double img2, double reel2)
{
	*img = *img + img2;
	*reel = *reel + reel2;
}

void	multiplication(double *img, double *reel, double img2, double reel2)
{
	double	temp;

	temp = *reel;
	*reel = *reel * reel2 - *img * img2;
	*img = temp * img2 + *img * reel2;
}

int	set_display(int i, int *display)
{
	if (i <= 10)
		*display = 10;
	else if (i <= 20)
		*display = 20;
	else if (i <= 30)
		*display = 20;
	else if (i <= 40)
		*display = 40;
	else if (i <= 50)
		*display = 50;
	else if (i <= 70)
		*display = 70;
	else if (i <= 90)
		*display = 90;
	else if (i <= 100)
		*display = 100;
	return (1);
}

void	mandelbrot(t_params *par, int i, int j)
{
	double	i_scaled;
	double	j_scaled;
	int		index;

	index = 0;
	par->z1 = 0;
	par->z2 = 0;
	i_scaled = scale(-2, 2, i) * par->facteur;
	j_scaled = scale(2, -2, j) * par->facteur;
	par->display = 0;
	while (index <= 100)
	{
		multiplication(&par->z2, &par->z1, par->z2, par->z1);
		somme(&par->z2, &par->z1, j_scaled, i_scaled);
		if (set_display(index, &par->display) && print_color(par, i, j) == 0)
		{
			index++;
		}
		else
			break ;
	}
}
