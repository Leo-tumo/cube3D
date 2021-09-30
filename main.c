#include "cube3d.h"

int map[24][24] = {
        
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
            {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
            {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,3,0,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,3,0,0,0,0,2,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,3,0,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,3,0,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
        };

void draw(/* void *mlx_ptr, void *mlx_win_ptr */)
{
    

    dcoor.posX = 22.0;
    dcoor.posY = 12.0;  //x and y start position
    dcoor.dirX = -1.0;
    dcoor.dirY = 0.0; //initial direction vector
    dcoor.planeX = 0.0; 
    dcoor.planeY = 0.66;
    for(int x = 0; x < 1040; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)1040 - 1; //x-coordinate in camera space
      double rDX = dcoor.dirX + dcoor.planeX*cameraX;
      double rDY = dcoor.dirY + dcoor.planeY*cameraX;

      //which box of the map we're in
      coor.mapX = (int)dcoor.posX;
      coor.mapY = (int)dcoor.posY;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

      //length of ray from one x or y-side to next x or y-side
      double deltaDistX = (rDX == 0) ? 1e30 : fabs(1 / rDX);
      double deltaDistY = (rDY == 0) ? 1e30 : fabs(1 / rDY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?

      //calculate step and initial sideDist
      if(rDX < 0)
      {
        stepX = -1;
        sideDistX = (dcoor.posX - coor.mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (coor.mapX + 1.0 - dcoor.posX) * deltaDistX;
      }
      if(rDY < 0)
      {
        stepY = -1;
        sideDistY = (dcoor.posY - coor.mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (coor.mapY + 1.0 - dcoor.posY) * deltaDistY;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          coor.mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          coor.mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if(map[coor.mapX][coor.mapY] > 0) hit = 1;
      }

      //Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

      //Calculate height of line to draw on screen
    //   int lineHeight = (int)(540 / perpWallDist);


    //   int pitch = 100;

      //calculate lowest and highest pixel to fill in current stripe
    //   int drawStart = -lineHeight / 2 + h / 2 + pitch;
    //   if(drawStart < 0) drawStart = 0;
    //   int drawEnd = lineHeight / 2 + h / 2 + pitch;
    //   if(drawEnd >= h) drawEnd = h - 1;

      //texturing calculations
    //   int texNum = data.coor.macoor.mapY] - 1; //1 subtracted from it so that texture 0 can be used!

    //   //calculate value of wallX
    //   double wallX; //where exactly the wall was hit
    //   if(side == 0) wallX = dcoor.posY + perpWallDist * rDY;
    //   else          wallX = dcoor.posX + perpWallDist * rDX;
    //   wallX -= floor((wallX));

      int lineHeight = (int)(540 / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + 540 / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + 540 / 2;
      if(drawEnd >= 540) drawEnd = 540 - 1;

      //x coordinate on the texture
    //   int texX = int(wallX * double(texWidth));
    //   if(side == 0 && rDX > 0) texX = texWidth - texX - 1;
    //   if(side == 1 && rDY < 0) texX = texWidth - texX - 1;

      // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
      // How much to increase the texture coordinate per screen pixel
    //   double step = 1.0 * texHeight / lineHeight;
    //   // Starting texture coordinate
    //   double texPos = (drawStart - pitch - h / 2 + lineHeight / 2) * step;

    int color;
    // 
    switch (map[coor.mapX][coor.mapY])
    {
        case 1:
            color = 0x00FF0000;
            break;
        case 2:
            color = 0x0000FF00;
            break;
        case 3:
            color = 0x000000FF;
            break;
        
        default:
            color = 0x00000000;
            break;
    }
      for(int y = drawStart; y < drawEnd; y++)
      {
          mlx_pixel_put(data.mlx, data.win, x, y, color);
      }
  }

    // drawBuffer(buffer[0]);
    // for(int y = 0; y < h; y++) for(int x = 0; x < w; x++) buffer[y][x] = 0; //clear the buffer instead of cls()
    //timing for input and FPS counter
    // oldTime = time;
    // time = getTicks();
    // double frameTime = (time - oldTime) / 1000.0; //frametime is the time this frame has taken, in seconds
    // print(1.0 / frameTime); //FPS counter
    // redraw();

    
}

//     readKeys();
  int   keypress(int key)
  {
//     //move forward if no wall in front of you
    if(key == 'W')
    {
      if(map[(int)(dcoor.posX + dcoor.dirX * cam.moveSpeed)][(int)(dcoor.posY)] == 0) dcoor.posX += dcoor.dirX * cam.moveSpeed;
      if(map[(int)(dcoor.posX)][(int)(dcoor.posY + dcoor.dirY * cam.moveSpeed)] == 0) dcoor.posY += dcoor.dirY * cam.moveSpeed;
    }
//     //move backwards if no wall behind you
    if(key == 'S')
    {
      if(map[(int)(dcoor.posX - dcoor.dirX * cam.moveSpeed)][(int)(dcoor.posY)] == 0) dcoor.posX -= dcoor.dirX * cam.moveSpeed;
      if(map[(int)(dcoor.posX)][(int)(dcoor.posY - dcoor.dirY * cam.moveSpeed)] == 0) dcoor.posY -= dcoor.dirY * cam.moveSpeed;
    }
    //rotate to the right
    if(key == 'D')
    {
      //both camera direction and camera plane must be rotated
      double oDX = dcoor.dirX;
      dcoor.dirX = dcoor.dirX * cos(-cam.rotSpeed) - dcoor.dirY * sin(-cam.rotSpeed);
      dcoor.dirY = oDX * sin(-cam.rotSpeed) + dcoor.dirY * cos(-cam.rotSpeed);
      double oPX = dcoor.planeX;
      dcoor.planeX = dcoor.planeX * cos(-cam.rotSpeed) - dcoor.planeY * sin(-cam.rotSpeed);
      dcoor.planeY = oPX * sin(-cam.rotSpeed) + dcoor.planeY * cos(-cam.rotSpeed);
    }
    //rotate to the left
    if(key == 'A')
    {
      //both camera direction and camera plane must be rotated
      double oDX = dcoor.dirX;
      dcoor.dirX = dcoor.dirX * cos(cam.rotSpeed) - dcoor.dirY * sin(cam.rotSpeed);
      dcoor.dirY = oDX * sin(cam.rotSpeed) + dcoor.dirY * cos(cam.rotSpeed);
      double oPX = dcoor.planeX;
      dcoor.planeX = dcoor.planeX * cos(cam.rotSpeed) - dcoor.planeY * sin(cam.rotSpeed);
      dcoor.planeY = oPX * sin(cam.rotSpeed) + dcoor.planeY * cos(cam.rotSpeed);
    }
    if(key == 53)
    {
      exit(0);
    }
    return 0;
  }

/* 
int *syncfunc(void *param)
{
    draw();

} */
int func()
{
	draw();
	mlx_put_image_to_window(data.mlx, data.win, data.img, 400, 500);
	return (0);
}

int main(int argc, char **argv)
{
    // void *mlx_ptr;
    // void *mlx_win_ptr;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx,  1040 , 540 ,  "title" );
    data.img = mlx_new_image(data.mlx, 1040, 540);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    mlx_hook(data.win, 2, (1L << 0), keypress, &data);
    mlx_key_hook(data.win, keypress, &data);
    // draw(data.mlx, data.win);
    mlx_loop_hook(data.mlx, func, &data);
    mlx_do_sync(data.mlx);
    mlx_loop(data.mlx);
}