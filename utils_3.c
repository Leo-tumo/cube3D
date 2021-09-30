#include "cube3d.h"

// int minimap_size(void)
// {
//     return(S_H / (mapY * 10));
// }

void    draw_quads(int x, int y, int x1, int y1, int color)
{
    int x0;

    while(y <= y1)
    {
        x0 = x;
        while(x0 <= x1)
        {
            my_mlx_pixel_put(&data, x0, y, color);
            ++x0;
        }
        ++y;
    }
}

// void draw_cubes(int x, int y, int delta, int color)
// {
//     int x1;
//     int y1;

//     y1 = y;
//    while(y1 < y + delta)
//    {
//        x1 = x;
//        while(x1 < x + delta)
//        {
//            my_mlx_pixel_put(&data, x1, y1, color);
//            ++x1;
//        }
//        ++y1;
//    }
// }