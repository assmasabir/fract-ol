/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:39:53 by asabir            #+#    #+#             */
/*   Updated: 2024/05/10 17:24:12 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H

double  scale(double x, double a, double b, double min, double max);
int    print_color(double i, double j, char *addr, int bpp, int line_len, int k, int b);
void mandelbrot_equation(int max_hight, int max_width, char*address,int bpp, int line_len);
#endif 