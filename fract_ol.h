/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:39:53 by asabir            #+#    #+#             */
/*   Updated: 2024/05/14 21:53:07 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H

typedef struct param
{
    int facteur;   
    int bits_per_pixel;
    int line_len;
    int endian;
    void    *img;
    void    *connection;
    void    *window;
    char    *address;
} t_param;

double  scale(double x, double a, double b, double min, double max);
int    print_color(double i, double j, char *addr, int bpp, int line_len, int k, int b, int display);
void mandelbrot_equation(int max_hight, int max_width, char*address,int bpp, int line_len);
#endif