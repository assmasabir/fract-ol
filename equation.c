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
    //double c;

    z1 = 0;
    z2 = 0;
    index = 0;
    k = 0;
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
            while(index < 200)
            {
                produit(&z1,&z2,z1, z2);
                somme(&z1,&z2, k_scaled, j_scaled);
                // printf("z1 =%f z2=%f\n", z1, z2);
                // if (index == 20)
                // exit(0);
                if(print_color(z1, z2,address, bpp, line_len, k, j)==0)
                    index++;
                else
                    break;
            }
            j++;
        }
        k++;
    }
}