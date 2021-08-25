#include "cube3d.h"
#include <stdio.h>

double px, py, pdx, pdy, pa;

int keypress(int keycode);


void	draw_ray()
{
	
	double i, j, a, k;
	k = 1;
	double pdx1, pdy1;
	a = pa - 0.75;
	while(a <= (pa + 0.75))
	{
		while (k < 20)
		{
			pdx1 = cos(a)*5;
			pdy1 = sin(a)*5;
			i = px + 4.5 + (pdx1 * k)  /* * 5 */;
			j = py + 4.5 + (pdy1 * k)  /* * 5 */;
			my_mlx_pixel_put(&data, i, j, 0x00FFFF00);
			k += 0.1;
		}
		printf("a = %f\n", a);
		a += 0.1;
	}
}

void	drawPlayer()
{
	int i,j;

	i = px + 8;
	while(i > px)
	{
		j = py + 8;
		while(j > py)
		{
			my_mlx_pixel_put(&data, i, j, 0x00FFFF00);
			--j;
		}
		--i;
	}
	draw_ray();
	// double k;
	// k = 1;
	
	// while (k < 20)
	// {
	// 	i = px + 4.5 + (pdx * k) /* * 5 */;
	// 	j = py + 4.5 + (pdy * k) /* * 5 */;
	// 	my_mlx_pixel_put(&data, i, j, 0x00FFFF00);
	// 	k += 0.1;
	// }
}



int mapX = 8, mapY = 8, mapS = 64;
int map[] = 
{
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 1, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
};


void	area_color(int color, int x1, int y1)
{
	int		x;
	int		y;

	y = 0;
	while(y < 720/mapY - 1)
	{
		x = 0;
		while(x < 720/mapX - 1)
		{
			my_mlx_pixel_put(&data, x + x1, y + y1, color);
			++x;
		}
		++y;
	}
}


void	draw_map2D()
{
	int x, y; /* xo, yo; */
	for(y = 0; y < mapY; y++)
	{
		for(x=0; x < mapX; x++)
		{
			if(map[y*mapX + x] == 1)
				area_color(0x00F8EFCE, x * 720/mapX, y * 720/mapY);
			else
				area_color(0x003A1B2F,x * 720/mapX, y * 720/mapY);
				
		}
	} 
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

void draw_frame()
{
	// mlx_clear_window(data.mlx,data.win);
	// clear_win();
	draw_map2D();
	drawPlayer();
}

int		keypress(int keycode /* , t_data *data */)
{
	
	if(keycode == 0) /* A */
		{
			pa -= PI/32;
			if(pa < 0)
				pa += 2*PI;
			pdx = cos(pa) * 5;
			pdy = sin(pa) * 5;
		}   
	if(keycode == 2) /* D */
		{
			pa += PI/32;
			if(pa > 2*PI)
				pa -= 2*PI;
			pdx = cos(pa) * 5;
			pdy = sin(pa) * 5;
		}   
	if(keycode == 13) /* W */
		{
			px += pdx;
			py += pdy;
		}
	if(keycode == 1) /* S */
		{
			px -= pdx;
			py -= pdy;
		}
	printf("pa =%f\n", pa);
	
	if(keycode == 53)
		exit(0);
	return(0); 
}
 


int func(struct s_data *s)
{
	draw_frame();
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	return (0);
}

int      main( void )
{

	data.x = 300;
	data.y = 300;
	px = 300;
	py = 300;
	pdx = cos(pa) * 5;
	pdy = sin(pa) * 5;

	data.mlx =  mlx_init();
	data.win =  mlx_new_window(data.mlx,  1280 ,  720 ,  "title" );
	data.img = mlx_new_image(data.mlx, 1280, 720);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_hook(data.win, 2, 1L << 0, keypress, &data);
	mlx_loop_hook(data.mlx, func, &data);
    mlx_loop(data.mlx);
}
