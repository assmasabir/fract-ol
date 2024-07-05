#include "fractol.h"

void julia(t_params *par, int i, int j)
{
    double i_scaled;
    double j_scaled;
    
    int index;
    index = 0;
    par->z1 = scale(-2, 2, 1000, 0, i)*par->facteur;
    par->z2 = scale(2, -2, 1000, 0, j)*par->facteur;
    i_scaled = par->j1;
    j_scaled = par->j2;
    par->display = 0;
    while(index<=100)
    {
        multiplication(&par->z2, &par->z1, par->z2, par->z1);
        somme(&par->z2, &par->z1, j_scaled, i_scaled);
        if(set_display(index, &par->display) && print_color(par, i, j)==0)
        {
            index++;
        }
        else
            break;
    }
}