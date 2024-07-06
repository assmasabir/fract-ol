/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elite <elite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:49:41 by elite             #+#    #+#             */
/*   Updated: 2024/07/06 13:56:05 by elite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct params
{
	void	*connection;
	void	*window;
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		display;
	double	z1;
	double	z2;
	double	facteur;
	double	j1;
	double	j2;
}			t_params;

int			print_color(t_params *par, int i, int j);
int			ft_strcmp(char *str1, char *str2);
int			set_display(int i, int *display);
int			mouse_hundler(int button, int x, int y, t_params *par);
void		mandelbrot(t_params *par, int i, int j);
double		scale(double a, double b, double i);
void		my_mlx_pixel_put(t_params *par, int j, int i, int color);
void		julia(t_params *par, int i, int j);
int			parse_input(int argc, char **argv, t_params *par);
void		multiplication(double *img, double *reel, double img2,
				double reel2);
void		somme(double *img, double *reel, double img2, double reel2);
#endif