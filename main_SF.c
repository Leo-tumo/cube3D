#include "cube3d.h"
//------------------------YouTube-3DSage----------------------------------------
//Full video: https://www.youtube.com/watch?v=gYRrGTC7GtA 
//WADS to move player.


//-----------------------------MAP----------------------------------------------
// double px, py, pdx, pdy, pa;
float px,py,pdx,pdy,pa;
int map[]=           //the map array. Edit to change level but keep the outer walls
{
 1,1,1,1,1,1,1,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,0,0,0,0,0,1,
 1,0,0,0,0,1,0,1,
 1,0,0,0,0,0,0,1,
 1,1,1,1,1,1,1,1,	
};

void drawMap2D()
{
	
 	int x,y,xo,yo;
	// int delta;

	
 	for(y=0;y<mapY;y++)
 	{
		for(x=0;x<mapX;x++)
  	{
		if(map[y*mapX+x]==1)
			draw_cubes(xo+1, yo+1,minimap_size(),0x00F3F2ED);
		else
		   draw_cubes(xo+1, yo+1,minimap_size()-1,0x003A1B2F);
   	xo=x*mapS/10; yo=y*mapS/10;
   	// glBegin(GL_QUADS); 
   	// glVertex2i( 0   +xo+1, 0   +yo+1); 
   	// glVertex2i( 0   +xo+1, mapS+yo-1); 
   	// glVertex2i( mapS+xo-1, mapS+yo-1);  
   	// glVertex2i( mapS+xo-1, 0   +yo+1); 
   	// glEnd();
  } 
 } 
}//-----------------------------------------------------------------------------


//------------------------PLAYER------------------------------------------------
float degToRad(int a) { return a*M_PI/180.0;}
int FixAng(int a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}


void drawPlayer2D()
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
	draw_line(px, py, px+pdx*20, py+pdy*20, 0x00FFF200);

	
//  glColor3f(1,1,0);   glPointSize(8);    glLineWidth(4);
//  glBegin(GL_POINTS); glVertex2i(px,py); glEnd();
//  glBegin(GL_LINES);  glVertex2i(px,py); glVertex2i(px+pdx*20,py+pdy*20); glEnd();
}

int keypress(int keycode)
{
 if(keycode==A){ pa+=5; pa=FixAng(pa); pdx=cos(degToRad(pa)); pdy=-sin(degToRad(pa));} 	
 if(keycode==D){ pa-=5; pa=FixAng(pa); pdx=cos(degToRad(pa)); pdy=-sin(degToRad(pa));} 
 if(keycode==W){ px+=pdx*5; py+=pdy*5;}
 if(keycode==S){ px-=pdx*5; py-=pdy*5;}
 if(keycode==153){exit(0);system("killall afplay");}
//  glutPostRedisplay();
return 0;
}//-----------------------------------------------------------------------------


//---------------------------Draw Rays and Walls--------------------------------
float distance(ax,ay,bx,by,ang){ return cos(degToRad(ang))*(bx-ax)-sin(degToRad(ang))*(by-ay);}

void drawRays2D()
{
	int colores;
//  glColor3f(0,1,1); glBegin(GL_QUADS); glVertex2i(526,  0); glVertex2i(1006,  0); glVertex2i(1006,160); glVertex2i(526,160); glEnd();
 draw_quads(526, 0, 1006, 160, 0x00A4DE02);
//  glColor3f(0,0,1); glBegin(GL_QUADS); glVertex2i(526,160); glVertex2i(1006,160); glVertex2i(1006,320); glVertex2i(526,320); glEnd();	 	
 draw_quads(526, 160, 1006, 320, 0x00051094);	
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
	
	colores = 0x007C0000;
	if(disV<disH){ rx=vx; ry=vy; disH=disV; colores = 0x00BF6902;}                  //horizontal hit first
	//   glLineWidth(2); glBegin(GL_LINES); glVertex2i(px,py); glVertex2i(rx,ry); glEnd();//draw 2D ray
	draw_line(px, py, rx, ry, colores);
		

	int ca=FixAng(pa-ra); disH=disH*cos(degToRad(ca));                            //fix fisheye 
	int lineH = (mapS*320)/(disH); if(lineH>320){ lineH=320;}                     //line height and limit
	int lineOff = 160 - (lineH>>1);                                               //line offset
	
	//   glLineWidth(8);glBegin(GL_LINES);glVertex2i(r*8+530,lineOff);glVertex2i(r*8+530,lineOff+lineH);glEnd();//draw vertical wall  
	draw_line(r*8+530, lineOff, r*8+530, lineOff+lineH, colores);
	ra=FixAng(ra-1);                                                              //go to next ray
	}
}//-----------------------------------------------------------------------------


void init()
{
//  glClearColor(0.3,0.3,0.3,0);
//  gluOrtho2D(0,1024,510,0);
 px=150; py=400; pa=90;
 pdx=cos(degToRad(pa)); pdy=-sin(degToRad(pa)); 
}

// void display()
// {   
//  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
//  drawMap2D();
//  drawPlayer2D();
//  drawRays2D();
//  glutSwapBuffers();  
// }

void draw_frame()
{

	drawMap2D();
 drawPlayer2D();
 drawRays2D();
}

int func(struct s_data *s)
{
	draw_frame();
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	return (0);
}
int main()
{ 
//  glutInit(&argc, argv);
//  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//  glutInitWindowSize(1024,510);
//  glutCreateWindow("YouTube-3DSage");
//  init();
//  glutDisplayFunc(display);
//  glutKeyboardFunc(Buttons);
//  glutMainLoop();
//  mlx_get_screen_size(data.mlx, &s_w, &s_h);
	data.x = 0;
	data.y = 0;
	px = 300;
	py = 300;
	pdx = cos(pa) * 5;
	pdy = sin(pa) * 5;
	// system("open -a ./cube3D");
	system("afplay son/journey.mp3 &");
	data.mlx =  mlx_init();
	data.win =  mlx_new_window(data.mlx,  S_W , S_H ,  "title" );
	data.img = mlx_new_image(data.mlx, S_W, S_H);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_hook(data.win, 2, 1L << 0, keypress, &data);
	mlx_loop_hook(data.mlx, func, &data);
    mlx_loop(data.mlx);
}

