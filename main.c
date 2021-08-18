#include "cube3d.h"
#include <stdio.h>

int      event_key( int  keycode, t_data *data)
{
    printf ( "keycode : %d\n" , keycode);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	if  (keycode ==  53)
        exit( 0 );
    return  ( 0 );
}

int		keypress(int keycode , t_data *data)
{
	if(keycode == 0)
		data->x -= 4; 
	if(keycode == 2)
		data->x += 4;
	if(keycode == 13)
		data->y -= 4;
	if(keycode == 1)
		data->y += 4;
	
	printf("x: %d\ny: %d\n", data->x, data->y);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	
	if(keycode == 53)
		exit(0);
	return(0); 
}
 
 int	render_next(t_data *data)
 {
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->x, data->y);
	return 0;
 }

int      main( void )
{
	int		img_height = 720;
	int 	img_width = 1280;
	char	*png_path = "pika.png";
    t_data data;
	data.x = 0;
	data.y =0;

	data.mlx =  mlx_init();
	data.win =  mlx_new_window(data.mlx,  1280 ,  720 ,  "title" );
	// data.img = mlx_new_image(data.mlx, 1280, 720);
	data.img = mlx_png_file_to_image(data.mlx, png_path , &img_width, &img_height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	// render_next_frame(&data, 0x00F3F6FB);
	// mlx_loop_hook(data.mlx, render_next_frame, &data);
   	
    mlx_hook(data.win,2, 0, keypress, &data);
	// mlx_put_image_to_window(data.mlx, data.win, data.img, data.x, data.y);
	// mlx_key_hook(data.win, render_next, &data);
	// mlx_hook(data.win,  2 ,  1L<<4 , event_key, &data);
   
    mlx_loop(data.mlx);
}