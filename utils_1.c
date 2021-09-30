#include "cube3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;
 
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


int     render_next_frame( t_data *data)
{
   
	int x = 0, y;
	while(x <= 1280)
	{
		y = 0;
		for(; y <= 720; y++)
		{
			// my_mlx_pixel_put(data, x, y, data->color);
			mlx_pixel_put(data->mlx, data->win, x, y, data->color);
		}
		x++;
	}


			switch (data->color)
			{
			case 0x000000FF:
				data->color = 0x0000FF00;
				break;
			case 0x0000FF00:
				data->color = 0x00FF0000;
				break;
			default:
				data->color = 0x000000FF;
				break;
			}
		
    return (0);
}

int  clear_win()
{
	int x , y = 0;

	while (y < 720)
	{
		x = 0;
		while (x < 1280)
		{
			my_mlx_pixel_put(&data, x, y, 0x00000000);
			++x;
		}
		++y;
	}
	return 0;
}


void draw_lineee(int x0, int y0, int x1, int y1, int color)
{
	int steps;
	double Xinc;
	double Yinc;
	double x;
	double y;
	int dx;
	int dy;
	 
	dx = (x1 - x0);
	dy = (y1 - y0);

	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	Xinc = dx / (double)steps;
	Yinc = dy / (double)steps;

	x = x0;
	y = y0;
	for (int i = 0; i <= steps; i++)
	{
    	my_mlx_pixel_put(&data, x, y, color);
    	x += Xinc;
    	y += Yinc;
	}
}