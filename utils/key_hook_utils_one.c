/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <letumany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:33:04 by letumany          #+#    #+#             */
/*   Updated: 2021/10/05 21:12:34 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_cub *cub, double s)
{
	if (cub->p.map[(int)(cub->plr.y + cub->plr.dir_y * s)]
								[(int)(cub->plr.x)] == '*')
		cub->plr.y += cub->plr.dir_y * s;
	if (cub->p.map[(int)(cub->plr.y)]
			[(int)(cub->plr.x + cub->plr.dir_x * s)] == '*')
		cub->plr.x += cub->plr.dir_x * s;
}

void	move_back(t_cub *cub, double s)
{
	if (cub->p.map[(int)(cub->plr.y - cub->plr.dir_y * s)]
								[(int)(cub->plr.x)] == '*')
		cub->plr.y -= cub->plr.dir_y * s;
	if (cub->p.map[(int)(cub->plr.y)]
			[(int)(cub->plr.x - cub->plr.dir_x * s)] == '*')
		cub->plr.x -= cub->plr.dir_x * s;
}

void	move_left(t_cub *cub, double s)
{
	if (cub->p.map[(int)(cub->plr.y - cub->plr.dir_x * s)]
								[(int)(cub->plr.x)] == '*')
		cub->plr.y -= cub->plr.dir_x * s;
	if (cub->p.map[(int)(cub->plr.y)]
			[(int)(cub->plr.x + cub->plr.dir_y * s)] == '*')
		cub->plr.x += cub->plr.dir_y * s;
}

void	move_right(t_cub *cub, double s)
{
	if (cub->p.map[(int)(cub->plr.y + cub->plr.dir_x * s)]
								[(int)(cub->plr.x)] == '*')
		cub->plr.y += cub->plr.dir_x * s;
	if (cub->p.map[(int)(cub->plr.y)]
			[(int)(cub->plr.x - cub->plr.dir_y * s)] == '*')
		cub->plr.x -= cub->plr.dir_y * s;
}

void	turn_right(t_cub *cub, double r)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->plr.dir_y;
	old_plane_x = cub->plr.plane_y;
	cub->plr.dir_y = cub->plr.dir_y * cos(-r) - cub->plr.dir_x * sin(-r);
	cub->plr.dir_x = old_dir_x * sin(-r) + cub->plr.dir_x * cos(-r);
	cub->plr.plane_y = cub->plr.plane_y * cos(-r) - cub->plr.plane_x * sin(-r);
	cub->plr.plane_x = old_plane_x * sin(-r) + cub->plr.plane_x * cos(-r);
}

void	turn_left(t_cub *cub, double r)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = cub->plr.dir_y;
	old_plane_x = cub->plr.plane_y;
	cub->plr.dir_y = cub->plr.dir_y * cos(r) - cub->plr.dir_x * sin(r);
	cub->plr.dir_x = old_dir_x * sin(r) + cub->plr.dir_x * cos(r);
	cub->plr.plane_y = cub->plr.plane_y * cos(r) - cub->plr.plane_x * sin(r);
	cub->plr.plane_x = old_plane_x * sin(r) + cub->plr.plane_x * cos(r);
}
