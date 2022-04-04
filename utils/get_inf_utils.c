/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inf_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <letumany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:24:10 by letumany          #+#    #+#             */
/*   Updated: 2021/10/05 21:12:28 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** get floore & check
*/
void	get_floore(char *tmp, t_cub *cub)
{
	if (ft_isdigit(*tmp))
		cub->p.floore_r = ft_atoi(tmp);
	else
		error("Error\nNot set floore_r", cub);
	tmp += ft_digit_num(cub->p.floore_r) + 1;
	if (ft_isdigit(*tmp))
		cub->p.floore_g = ft_atoi(tmp);
	else
		error("Error\nNot set floore_g", cub);
	tmp += ft_digit_num(cub->p.floore_g) + 1;
	if (ft_isdigit(*tmp))
		cub->p.floore_b = ft_atoi(tmp);
	else
		error("Error\nNot set floore_b", cub);
}

/*
** get ceilling & check
*/
void	get_ceilling(char *tmp, t_cub *cub)
{
	if (ft_isdigit(*tmp))
		cub->p.ceilling_r = ft_atoi(tmp);
	else
		error("Error\nNot set ceilling_r", cub);
	tmp += ft_digit_num(cub->p.ceilling_r) + 1;
	if (ft_isdigit(*tmp))
		cub->p.ceilling_g = ft_atoi(tmp);
	else
		error("Error\nNot set ceilling_g", cub);
	tmp += ft_digit_num(cub->p.ceilling_g) + 1;
	if (ft_isdigit(*tmp))
		cub->p.ceilling_b = ft_atoi(tmp);
	else
		error("Error\nNot set ceilling_b", cub);
}

/*
** get sprite & check
*/
void	get_sprite(t_cub *cub)
{
	int width;
	int height;

	if (!(cub->t_spr.img = mlx_xpm_file_to_image(cub->mlx, cub->p.spr_tex, &width, &height)))
		error("Error\nNo texture found for the sprite", cub);
	cub->t_spr.addr = mlx_get_data_addr(cub->t_spr.img,&cub->t_spr.bits_per_pixel, &cub->t_spr.line_length, &cub->t_spr.endian);
	if (!(cub->t_n.img = mlx_xpm_file_to_image(cub->mlx, cub->p.nor_tex, &width, &height)))
		error("Error\nNo texture found for North", cub);
	cub->t_n.addr = mlx_get_data_addr(cub->t_n.img, &cub->t_n.bits_per_pixel, &cub->t_n.line_length, &cub->t_n.endian);
	if (!(cub->t_s.img = mlx_xpm_file_to_image(cub->mlx, cub->p.sou_tex, &width, &height)))
		error("Error\nNo texture found for the South", cub);
	cub->t_s.addr = mlx_get_data_addr(cub->t_s.img, &cub->t_s.bits_per_pixel, &cub->t_s.line_length, &cub->t_s.endian);
	if (!(cub->t_w.img = mlx_xpm_file_to_image(cub->mlx, cub->p.wes_tex, &width, &height)))
		error("Error\nNo texture found for the West", cub);
	cub->t_w.addr = mlx_get_data_addr(cub->t_w.img, &cub->t_w.bits_per_pixel, &cub->t_w.line_length, &cub->t_w.endian);
	if (!(cub->t_e.img = mlx_xpm_file_to_image(cub->mlx, cub->p.eas_tex, &width, &height)))
		error("Error\nNo texture found for the East", cub);
	cub->t_e.addr = mlx_get_data_addr(cub->t_e.img, &cub->t_e.bits_per_pixel, &cub->t_e.line_length, &cub->t_e.endian);
}
