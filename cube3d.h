#ifndef CUBE3D_H
#define CUBE3D_H

// #define mapX  8      //map width
// #define mapY  8      //map height
#define mapS 64      //map cube size
// #include "libs/minilibx_mms/mlx.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define PI 3.14159265359
#define W 13
#define A 0
#define S 1
#define D 2
#define S_W 1024
#define S_H 510



typedef struct s_data {
	void	*img;
	void	*mlx;
	char	*addr;
	void	*win;
	int		color;
	int      x;
    int      y;
	int		**map;
	int		bits_per_pixel;
	int 	line_length;
	int		endian;
	// int		*map;
}
			t_data;

t_data data;

// typedef struct		s_coor
// {
// 	int				x;
// 	int				y;
// }					t_coor;

typedef struct		s_dcoor
{
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			rayDirX;
	double			rayDirY;
}	t_dcoor;

typedef struct		s_coor
{
	int				mapX;
	int				mapY;
}	t_coor;

t_coor	coor;
t_dcoor	dcoor;

typedef struct		s_bmp
{
	int				size;
	char			*img;
	unsigned char	header[14];
	unsigned char	info[40];
	unsigned char	pad[3];
	int				color;
	int				fd;
}					t_bmp;

typedef struct		s_mlx
{
	void			*ptr;
	void			*winptr;
	void			*imgptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				*get_data;
	int				w;
	int				h;
	int				color;
}					t_mlx;

typedef struct		s_mvt
{
	t_coor			up;
	t_coor			side;
	t_coor			rot;
	int				hud;
	int				msc;
	double			life;
	int				diffsp;
}					t_mvt;

typedef struct		s_cam
{
	double 			rotSpeed;
	double			moveSpeed;
	t_dcoor			pos;
	t_dcoor			raypos;
	t_coor			map;
	t_dcoor			ori;
	t_dcoor			raydir;
	int				isit;
	double			speed;
	double			vitrot;
}					t_cam;

t_cam				cam;

typedef struct		s_algo
{
	t_dcoor			len;
	t_dcoor			delta;
	t_coor			dir;
	int				nseo;
	double			newlong;
	double			hauteurligne;
	t_dcoor			plane;
	double			colx;
	double			pdist;
	double			drawstart;
	double			drawend;
	t_dcoor			trans;
	int				spscreen;
	t_coor			start;
	t_coor			end;
	int				texsp_x;
}					t_algo;

typedef struct		s_texture
{
	void			*ptr;
	int				*data;
	int				bpp;
	int				line_size;
	int				endian;
	int				h;
	int				w;
	int				color;
}					t_texture;

typedef struct		s_info
{
	char			*n;
	char			*s;
	char			*e;
	char			*w;
	char			*i;
	unsigned int	c;
	unsigned int	f;
	t_coor			res;
	t_coor			maplen;
	char			*bufmap;
	int				test[256];
}					t_info;

typedef struct		s_sprites
{
	t_dcoor			coor;
	double			dist;
	int				ordre;
	t_mlx			img;
}					t_sprites;

typedef struct		s_spr
{
	int				nbsp;
	t_dcoor			camsp;
	t_dcoor			trans;
	t_coor			start;
	t_coor			end;
	int				spscreen;
	int				sph;
	int				spw;
	t_coor			texsp;
	double			*distwall;
}					t_spr;

typedef struct		s_all
{
	t_algo			algo;
	t_info			info;
	t_mlx			mlx;
	t_cam			cam;
	t_mvt			mvt;
	t_spr			spr;
	t_texture		texturen;
	t_texture		textures;
	t_texture		texturee;
	t_texture		texturew;
	t_mlx			hand;
	t_mlx			hud;
	t_sprites		*sprites;
}					t_all;

void		drawRays2D();
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	    	key_hook(int keycode/*, t_vars *vars*/);
void		screen_color(void *mlx);
void 		draw_cubes(int x, int y, int delta, int color);
void   		draw_quads(int x, int y, int x1, int y1, int color);
int			keypress(int keycode);
void		draw_line(int x0, int y0, int x1, int y1, int color);
int 		clear_win();
int 		minimap_size(void);
int			FixAng(int a);
float		degToRad(int a);
void		area_color(int color, int x1, int y1);
#endif