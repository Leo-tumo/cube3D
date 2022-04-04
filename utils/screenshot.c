/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <letumany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:51:28 by letumany          #+#    #+#             */
/*   Updated: 2021/10/06 13:32:36 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** fill screenshot
*/
static	void	fill_screen(int fd, t_cub *cub)
{
	int i;
	int j;
	int color;

	i = cub->p.res_l;
	while (--i >= 0)
	{
		j = -1;
		while (++j < cub->p.res_w)
		{
			color = get_pixel(&cub->data, j, i);
			write(fd, &color, 4);
		}
	}
	exit(0);
}	

/*
** screenshot
*/
void			screenshot(t_cub *cub)
{
	int		fd;
	int		all_pix;
	int		zero;
	int		pos_pix;
	int		size;
	short	plane;
	
	fd = open("screen.bmp", O_CREAT | O_RDWR, 0666);
	all_pix = cub->p.res_w * cub->p.res_l * 4 + 54;
	zero = 0;
	pos_pix = 54;
	size = cub->p.res_w * cub->p.res_l;
	write(fd, "BM", 2);
	write(fd, &all_pix, 4);
	write(fd, &zero, 4);
	write(fd, &pos_pix, 4);
	pos_pix = 40;
	write(fd, &pos_pix, 4);
	write(fd, &cub->p.res_w, 4);
	write(fd, &cub->p.res_l, 4);
	plane = 1;
	write(fd, &plane, 2);
	plane = 32;
	write(fd, &plane, 2);
	write(fd, &zero, 4);
	write(fd, &size, 4);
	all_pix = 1000;
	write(fd, &all_pix, 4);
	write(fd, &all_pix, 4);
	write(fd, &zero, 4);
	write(fd, &zero, 4);
	fill_screen(fd, cub);
}
