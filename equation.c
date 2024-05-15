#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "fract_ol.h"
void somme(double *reel, double *img, double reel2, double img2)
{
    *reel = *reel + reel2;
    *img = (*img) + img2;
}
void produit(double *reel, double *img, double reel2, double img2)
{
    double temp; 
    temp = *reel;
    *reel = temp * reel2 - (*img) * img2;
    *img = img2 * temp + (*img) * reel2;
}

void mandelbrot_equation(int max_hight, int max_width, char*address,int bpp, int line_len )
{
    double z1;
    double z2;
    double k;
    double j;
    double index;
    double  k_scaled;
    double  j_scaled;
    int display;
    // t_param *tpar;
    // tpar = malloc(sizeof(t_param));
    //double c;

    z1 = 0;
    z2 = 0;
    index = 0;
    k = 0;
    display =0;
    while( k != max_hight)
    {
        j = 0;
        while(j != max_width)
        {
            index = 0;
            z1 = 0;
            z2 = 0;
            k_scaled = scale(k, -2, 2, 0, 800);
            j_scaled = scale(j, 2, -2, 0, 800);
            while(index <= 50)
            {
                display =0;
                produit(&z1,&z2,z1, z2);
                somme(&z1,&z2, k_scaled, j_scaled);
                if(index<=5)
                    display=5;
                else if(index<=10)
                    display=10;
                else if(index<=20)
                    display = 20;
                else if(index<=30)
                    display = 30;
                else if(index<=40)
                    display = 40;
                else if(index<=50)
                    display =50;
                if(print_color(z1, z2,address, bpp, line_len, k, j, display)==0)
                    index++;
                else
                    break;
            }
            j++;
        }
        k++;
    }
}