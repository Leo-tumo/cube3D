#include "cube3d.h"
#include <stdio.h>

int s_w = 1024;
int	s_h = 510;


double px, py, pdx, pdy, pa;
int keypress(int keycode);

// int mapX = 8, mapY = 8, mapS = 64;
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
void init()
{
 px=150; py=400; pa=90;
 pdx=cos(degToRad(pa)); pdy=-sin(degToRad(pa)); 
}

// void	draw_ray(double pdx1, double pdy1, int color)
// {
// 	// double i, j;
// 	// double	k = 0;
// 	double  ra; /* ray angle */
// 	double 	rx; /* rayx start */
// 	double 	ry; /* rayy start */
// 	double 	yo; /* step by vertical up/down */
// 	double 	xo; /* step by horizontal left/right*/
// 	// double 	aTan; /* 1/tan(ra) */
// 	int 	r; /* counter */
// 	int 	mx; /* x coordinate of map */
// 	int 	my; /* y coordinate of map */
// 	int 	mp; /* position in map */
// 	int 	dof; /* depth of field */
	
	
// 	ra = pa;
// 	r = 0;



// 	while(r < 1)
// 	{
// 		dof = 0;
// 		// aTan = -1/tan(ra);
// 		if(ra == 0 || ra == PI || ra == 2*PI)
// 		{
// 			rx = px;
// 			ry = py;
// 			dof = 8;
// 		}

// 		if(ra > PI && ra < 2*PI)/* look up */
// 		{
// 			ry = (((int)py >> 6)<< 6);
// 			// rx = (py - ry) * aTan + px;
// 			rx = pdy == 0 ? 0 : ((ry-py) / pdy1) * pdx1 + px;
// 			yo = -64;
// 			// xo = -yo * aTan;
// 			xo = pdy1 == 0 ? 0 : -yo/(pdy1 * pdx1);
// 		}
// 		if(ra < PI && ra > 0)/* look down */
// 		{
// 			ry = (((int)py >> 6)<< 6) + 64;
// 			// rx = (py - ry) * aTan + px;
// 			rx = pdy == 0 ? 0 : ((ry-py )/ pdy1) * pdx1 + px;
// 			yo = 64;
// 			// xo = -yo * aTan;
// 			xo = pdy1 == 0 ? 0 : -yo/(pdy1 * pdx1);
// 		}
		
// 		while(dof < 8)
// 		{
// 			mx = (int)rx >> 6;
// 			my = (int)ry >> 6;
// 			mp = my * mapX + mx;
// 			if((mp < mapX * mapY) && (map[mp] == 1))
// 				dof = 8;
// 			else
// 			{
// 				rx += xo;
// 				ry += yo; 
// 				dof += 1;
// 			}
// 		}

// 		draw_line( px, py, rx, ry, color);
		
	
// 		r++;
	
// 	// while (k < 20)
// 	// {
// 	// 	i = px + 4 + (pdx1 * k)  /* * 5 */;
// 	// 	j = py + 4 + (pdy1 * k)  /* * 5 */;
// 	// 	my_mlx_pixel_put(&data, i, j, color);
// 	// 	// mlx_pixel_put(data.mlx, data.win, i, j, color);
// 	// 	// my_mlx_pixel_put(&data, xo, yo, color);
// 	// 	k += 0.2;
// 	// }
// 	}
// }

void	drawPlayer()
{
	int i,j;

	i = px + 4;
	while(i > px-4)
	{
		j = py + 4;
		while(j > py - 4)
		{
			my_mlx_pixel_put(&data, i, j, 0x00FFFF00);
			--j;
		}
		--i;
	}

	
	/* draying other rays */
	/* double a, pdx1, pdy1;
	a = pa-0.75;
	while(a <= (pa+0.75))
	{
	pdx1 = cos(a) *5;
	pdy1 = sin(a) *5;
	draw_ray(pdx1, pdy1, 0x007FFF00);
	a += 0.03;
	} */
	/* draw direction ray */
	
	
	// draw_line(24, 220, 900, 600, 0x00A10FD6);
}




void	draw_map2D()
{
	int x, y;
	for(y = 0; y < mapY; y++)
	{
		for(x=0; x < mapX; x++)
		{
			if(map[y*mapX + x] == 1)
				area_color(0x00F3F2ED, x * s_h/mapX, y * s_h/mapY);
			else
				area_color(0x003A1B2F,x * s_h/mapX, y * s_h/mapY);
				
		}
	} 
}

void draw_frame()
{
	// mlx_clear_window(data.mlx,data.win)
	
	draw_map2D(); 
	drawPlayer();
	drawRays2D();
	draw_quads(600, 200, 800, 400, 0x0073A294);
	draw_cubes(1000, 400, 200, 0x006A5B4C);
}

int func(struct s_data *s)
{
	draw_frame();
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	return (0);
}

int      main( void )
{
	mlx_get_screen_size(data.mlx, &s_w, &s_h);
	data.x = 0;
	data.y = 0;
	px = 300;
	py = 300;
	pdx = cos(pa) * 5;
	pdy = sin(pa) * 5;
	// system("open -a ./cube3D");
	system("afplay son/journey.mp3 &");
	data.mlx =  mlx_init();
	data.win =  mlx_new_window(data.mlx,  s_w , s_h ,  "title" );
	data.img = mlx_new_image(data.mlx, s_w, s_h);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_hook(data.win, 2, 1L << 0, keypress, &data);
	mlx_loop_hook(data.mlx, func, &data);
    mlx_loop(data.mlx);
}



























void drawRays2D()
{
int r,mx,my,mp,dof,side; float vx,vy,rx,ry,ra,xo,yo,disV,disH; 
 
 ra=FixAng(pa+30);                                                              //ray set back 30 degrees
 
 for(r=0;r<60;r++)
 {
  //---Vertical--- 
  dof=0; side=0; disV=100000;
  float Tan=tan(degToRad(ra));
       if(cos(degToRad(ra))> 0.001){ rx=(((int)px>>6)<<6)+64;      ry=(px-rx)*Tan+py; xo= 64; yo=-xo*Tan;}//looking left
  else if(cos(degToRad(ra))<-0.001){ rx=(((int)px>>6)<<6) -0.0001; ry=(px-rx)*Tan+py; xo=-64; yo=-xo*Tan;}//looking right
  else { rx=px; ry=py; dof=8;}                                                  //looking up or down. no hit  

  while(dof<8) 
  { 
   mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;                     
   if(mp>0 && mp<mapX*mapY && map[mp]==1){ dof=8; disV=cos(degToRad(ra))*(rx-px)-sin(degToRad(ra))*(ry-py);}//hit         
   else{ rx+=xo; ry+=yo; dof+=1;}                                               //check next horizontal
  } 
  vx=rx; vy=ry;

  //---Horizontal---
  dof=0; disH=100000;
  Tan=1.0/Tan; 
       if(sin(degToRad(ra))> 0.001){ ry=(((int)py>>6)<<6) -0.0001; rx=(py-ry)*Tan+px; yo=-64; xo=-yo*Tan;}//looking up 
  else if(sin(degToRad(ra))<-0.001){ ry=(((int)py>>6)<<6)+64;      rx=(py-ry)*Tan+px; yo= 64; xo=-yo*Tan;}//looking down
  else{ rx=px; ry=py; dof=8;}                                                   //looking straight left or right
 
  while(dof<8) 
  { 
   mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;                          
   if(mp>0 && mp<mapX*mapY && map[mp]==1){ dof=8; disH=cos(degToRad(ra))*(rx-px)-sin(degToRad(ra))*(ry-py);}//hit         
   else{ rx+=xo; ry+=yo; dof+=1;}                                               //check next horizontal
  } 
  
//   glColor3f(0,0.8,0);
  if(disV<disH){ rx=vx; ry=vy; disH=disV;/*  glColor3f(0,0.6,0); */}                  //horizontal hit first
//   glLineWidth(2); glBegin(GL_LINES); glVertex2i(px,py); glVertex2i(rx,ry); glEnd();//draw 2D ray
  draw_line(px, py, rx, ry, 0x00FFC0CB);
    
  int ca=FixAng(pa-ra); disH=disH*cos(degToRad(ca));                            //fix fisheye 
  int lineH = (mapS*320)/(disH); if(lineH>320){ lineH=320;}                     //line height and limit
  int lineOff = 160 - (lineH>>1);                                               //line offset
  
//   glLineWidth(8);glBegin(GL_LINES);glVertex2i(r*8+530,lineOff);glVertex2i(r*8+530,lineOff+lineH);glEnd();//draw vertical wall  
  draw_line(r*8+530,lineOff, r*8+530,lineOff+lineH, 0x007FFFD4);
  ra=FixAng(ra-1);                                                              //go to next ray
 }
}




















int		keypress(int keycode /* , t_data *data */)
{
	if(keycode == 0) /* A */
		{
			pa -= PI/16;
			if(pa < 0)
				pa += 2*PI;
			pdx = cos(pa) * 5;
			pdy = sin(pa) * 5;
		}   
	if(keycode == 2) /* D */
		{
			pa += PI/16;
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
	if(keycode == 53)
		{
			system("clear");
			system("killall afplay");
			exit(0);
		}	
	return(0); 
}


void	area_color(int color, int x1, int y1)
{
	int		x;
	int		y;

	y = 0;
	while(y < s_h/mapY)
	{
		x = 0;
		while(x < s_h/mapX)
		{
			if(y == (s_h/mapY - 1) || x == (s_h/mapX - 1))
				my_mlx_pixel_put(&data, x + x1, y + y1, 0x00000000);
			else
				my_mlx_pixel_put(&data, x + x1, y + y1, color);
			++x;
		}
		++y;
	}
}