# cube3D

## My first RayCaster with miniLibX
[![letumany's 42 cub3d Score](https://badge42.vercel.app/api/v2/cl1l8hert000609l6rjl6rx6o/project/2169830)](https://github.com/JaeSeoKim/badge42)

## Installation
```
make && ./cub3D maps/light.cub
```
## Usage


```
## Keybinds

Player Movement: 
- W: Move Forward
- S: Move Backwards
- D: Strafe right
- A: Strafe right
- Right Arrow: Rotate right
- Left Arrow: Rotate left
- ESC key: exit program

## Program

The program accepts two arguments, the first one is for the file with .cub extension that hosts the following:
- Screen Resolution
- Paths for textures and sprites
- RGB data for ceiling and floor
- The map itself represented by:
   - 0 for empty space
   - 1 for Walls
   - 2 for Sprites
The second argument, if "--save", will save the first rendered frame as a BMP file at the root of the project.
