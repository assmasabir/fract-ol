/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elite <elite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:49:34 by elite             #+#    #+#             */
/*   Updated: 2024/07/06 12:43:05 by elite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_destroy(t_params *par)
{
	mlx_destroy_window(par->connection, par->window);
	mlx_destroy_image(par->connection, par->img);
	mlx_destroy_display(par->connection);
	free(par->connection);
	free(par);
	exit(0);
}

void	fill_window(t_params *par, int check)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check == 0)
		return ;
	while (j < HEIGH)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (check == 1)
				mandelbrot(par, i, j);
			if (check == 2)
				julia(par, i, j);
			i++;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_params	*par;

	if (argc == 1)
	{
		write(2, "mandelbrot: mandelbrot\n julia: julia <real> <imaginary>\n",
			56);
		exit(EXIT_FAILURE);
	}
	par = malloc(sizeof(t_params));
	par->click[0] = 0;
	par->click[1] = 0;
	par->check = parse_input(argc, argv, par);
	par->facteur = 1;
	par->connection = mlx_init();
	par->window = mlx_new_window(par->connection, WIDTH, HEIGH, "fract-OL");
	par->img = mlx_new_image(par->connection, WIDTH, HEIGH);
	par->address = mlx_get_data_addr(par->img, &(par->bits_per_pixel),
			&(par->size_line), &(par->endian));
	mlx_hook(par->window, ON_DESTROY, 0, on_destroy, par);
	mlx_hook(par->window, ON_KEYDOWN, (1L << 0), press, par);
	mlx_hook(par->window, ON_KEYUP, (1L << 1), release, par);
	mlx_loop_hook(par->connection, mouse_hundler, par);
	mlx_loop(par->connection);
}
