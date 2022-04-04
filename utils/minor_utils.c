/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <letumany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:11:52 by letumany          #+#    #+#             */
/*   Updated: 2021/10/06 00:14:39 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** hex -> rgb
*/
int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

/*
** close window & exit
*/
int	close_win(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->mlx_win);
	exit(0);
	return (0);
}

/*
** faster mlx_pixel_put -> image
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*
** get pixel from texture
*/
unsigned	int	get_pixel(t_data *data, int x, int y)
{
	unsigned int	color;
	char			*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

/*
** free list map
*/
void	free_lst_map(t_list **lst)
{
	t_list *p;

	while (*lst)
	{
		p = (*lst)->next;
		free(*lst);
		*lst = p;
	}
	*lst = NULL;
}

/*
** set player direction
*/
void			set_dir_plr(t_cub *cub)
{
	if (cub->plr.dir_symbol == 'N')
	{
		cub->plr.dir_y = -1;
		cub->plr.dir_x = 0;
		cub->plr.plane_y = 0;
		cub->plr.plane_x = 0.66;
	}
	else if (cub->plr.dir_symbol == 'S')
	{
		cub->plr.dir_y = 1;
		cub->plr.dir_x = 0;
		cub->plr.plane_y = 0;
		cub->plr.plane_x = -0.66;
	}
	else if (cub->plr.dir_symbol == 'W')
	{
		cub->plr.dir_y = 0;
		cub->plr.dir_x = -1;
		cub->plr.plane_y = -0.66;
		cub->plr.plane_x = 0;
	}
	else if (cub->plr.dir_symbol == 'E')
	{
		cub->plr.dir_y = 0;
		cub->plr.dir_x = 1;
		cub->plr.plane_y = 0.66;
		cub->plr.plane_x = 0;
	}
}
