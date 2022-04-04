/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <letumany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 23:55:17 by letumany          #+#    #+#             */
/*   Updated: 2021/10/06 00:20:57 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	side_world(t_print_map *n, t_cub *cub, int *x, int *y)
{
	if (*y < n->draw_start)
		my_mlx_pixel_put(&cub->data, *x, *y,
		create_rgb(cub->p.ceilling_r, cub->p.ceilling_g, cub->p.ceilling_b));
	if (*y >= n->draw_start && *y <= n->draw_end)
		{
			n->tex_y = (int)n->tex_pos & (TEXHEIGHT - 1);
			n->tex_pos += n->step;
			if (n->side == 0)
			{
				if (n->step_x > 0)
					my_mlx_pixel_put(&cub->data, *x, *y,
					get_pixel(&cub->t_s, n->tex_x, n->tex_y));
				else
					my_mlx_pixel_put(&cub->data, *x, *y,
					get_pixel(&cub->t_n, n->tex_x, n->tex_y));
			}
			else
			{
				if (n->step_y > 0)
					my_mlx_pixel_put(&cub->data, *x, *y,
					get_pixel(&cub->t_e, n->tex_x, n->tex_y));
				else
					my_mlx_pixel_put(&cub->data, *x, *y,
					get_pixel(&cub->t_w, n->tex_x, n->tex_y));
			}
		}
	if (*y > n->draw_end && *y < cub->p.res_l)
		my_mlx_pixel_put(&cub->data, *x, *y,
		create_rgb(cub->p.floore_r, cub->p.floore_g, cub->p.floore_b));
}

void	calc_more(t_print_map *n, t_cub *cub, int *x)
{
	if (n->side == 0)
		n->perp_wall_dist = (n->map_x - cub->plr.y + (1 - n->step_x) / 2) / n->ray_dir_x;
	else
		n->perp_wall_dist = (n->map_y - cub->plr.x + (1 - n->step_y) / 2) / n->ray_dir_y;
	cub->close_sprite[*x] = n->perp_wall_dist;
	n->line_height = (int)(cub->p.res_l / n->perp_wall_dist);
	n->draw_start = -n->line_height / 2 + cub->p.res_l / 2;
	if (n->draw_start < 0)
		n->draw_start = 0;
	n->draw_end = n->line_height / 2 + cub->p.res_l / 2;
	if (n->draw_end >= cub->p.res_l)
		n->draw_end = cub->p.res_l - 1;
	if (n->side == 0)
		n->wall_x = cub->plr.x + n->perp_wall_dist * n->ray_dir_y;
	else
		n->wall_x = cub->plr.y + n->perp_wall_dist * n->ray_dir_x;
	n->wall_x -= floor((n->wall_x));
	n->tex_x = (int)(n->wall_x * (double)(TEXWIDTH));
	if (n->side == 0 && n->ray_dir_x > 0)
		n->tex_x = TEXWIDTH - n->tex_x - 1;
	if (n->side == 1 && n->ray_dir_y < 0)
		n->tex_x = TEXWIDTH - n->tex_x - 1;
}

void	check_hit(t_print_map *n, t_cub *cub)
{
	if (n->side_dist_x < n->side_dist_y)
	{
		n->side_dist_x += n->delta_dist_x;
		n->map_x += n->step_x;
		n->side = 0;
	}
	else
	{
		n->side_dist_y += n->delta_dist_y;
		n->map_y += n->step_y;
		n->side = 1;
	}
	if (cub->p.map[n->map_x][n->map_y] == '1')
		n->hit = 1;
}

void	calc_step_start(t_print_map *n, t_cub *cub)
{
	if (n->ray_dir_x < 0)
	{
		n->step_x = -1;
		n->side_dist_x = (cub->plr.y - n->map_x) * n->delta_dist_x;
	}
	else
	{
		n->step_x = 1;
		n->side_dist_x = (n->map_x + 1.0 - cub->plr.y) * n->delta_dist_x;
	}
	if (n->ray_dir_y < 0)
	{
		n->step_y = -1;
		n->side_dist_y = (cub->plr.x - n->map_y) * n->delta_dist_y;
	}
	else
	{
		n->step_y = 1;
		n->side_dist_y = (n->map_y + 1.0 - cub->plr.x) * n->delta_dist_y;
	}
}