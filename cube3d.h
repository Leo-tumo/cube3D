#ifndef CUBE3D_H
#define CUBE3D_H


#include "libs/minilibx_mms/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define PI 3.14159265359
#define W 13
#define A 0
#define S 1
#define D 2


typedef struct s_data {
	void	*img;
	void	*mlx;
	char	*addr;
	void	*win;
	int		color;
	int      x;
    int      y;
	int		bits_per_pixel;
	int 	line_length;
	int		endian;
}
			t_data;
			
typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		color;
}				t_vars;

t_data data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	    key_hook(int keycode/*, t_vars *vars*/);
void	screen_color(void *mlx);
int		pak(int keycode, t_vars *vars);

#endif