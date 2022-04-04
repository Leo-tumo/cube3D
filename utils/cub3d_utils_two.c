/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <letumany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:59:25 by letumany          #+#    #+#             */
/*   Updated: 2021/10/06 13:33:42 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_sprite(t_cub *cub, t_print_sprite *s, int *i)
{
	s->sprite_x = cub->x[*i] - cub->plr.x;
	s->sprite_y = cub->y[*i] - cub->plr.y;
	s->inv_det = 1.0 / (cub->plr.plane_x * cub->plr.dir_y
					- cub->plr.dir_x * cub->plr.plane_y);
	s->transform_x = s->inv_det * (cub->plr.dir_y * s->sprite_x
								- cub->plr.dir_x * s->sprite_y);
	s->transform_y = s->inv_det * (-cub->plr.plane_y * s->sprite_x
								+ cub->plr.plane_x * s->sprite_y);
	s->sprite_screen_x = (int)((cub->p.res_w / 2)
		* (1 + s->transform_x / s->transform_y));
	s->sprite_height = abs((int)(cub->p.res_l / (s->transform_y)));
	s->draw_start_y = -s->sprite_height / 2 + cub->p.res_l / 2;
	if (s->draw_start_y < 0)
		s->draw_start_y = 0;
	s->draw_end_y = s->sprite_height / 2 + cub->p.res_l / 2;
	if (s->draw_end_y >= cub->p.res_l)
		s->draw_end_y = cub->p.res_l - 1;
	s->sprite_width = abs((int)(cub->p.res_l / (s->transform_y)));
	s->draw_start_x = -s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_start_x < 0)
		s->draw_start_x = 0;
	s->draw_end_x = s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_end_x >= cub->p.res_w)
		s->draw_end_x = cub->p.res_w - 1;
}

void	print_sprite_part(t_cub *cub, t_print_sprite *s, int *y, int *stripe)
{
	*y = s->draw_start_y;
	while (*y < s->draw_end_y)
	{
		s->d = (*y) * 256 - cub->p.res_l
		* 128 + s->sprite_height * 128;
		s->tex_y = ((s->d * TEXHEIGHT) / s->sprite_height) / 256;
		s->color = get_pixel(&cub->t_spr, s->tex_x, s->tex_y);
		if (s->color != 0)
			my_mlx_pixel_put(&cub->data, *stripe, *y, s->color);
		(*y)++;
	}
}

void	set_cam_ray_mapxy(t_print_map *n, int *x, t_cub *cub)
{
	n->camera_x = 2 * *x / (double)cub->p.res_w - 1;
	n->ray_dir_x = cub->plr.dir_y + cub->plr.plane_y * n->camera_x;
	n->ray_dir_y = cub->plr.dir_x + cub->plr.plane_x * n->camera_x;
	n->map_x = (int)(cub->plr.y);
	n->map_y = (int)(cub->plr.x);
	n->delta_dist_x = sqrt(1 + (n->ray_dir_y * n->ray_dir_y) / (n->ray_dir_x * n->ray_dir_x));
	n->delta_dist_y = sqrt(1 + (n->ray_dir_x * n->ray_dir_x) / (n->ray_dir_y * n->ray_dir_y));
	n->hit = 0;
}
