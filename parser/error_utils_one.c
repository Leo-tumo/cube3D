/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <letumany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 10:15:20 by letumany          #+#    #+#             */
/*   Updated: 2021/10/13 21:45:34 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
** prints error code & exits
*/
void	error(char *str, t_cub *cub)
{
	(void)cub;
	ft_putendl_fd(str, 1);
	exit(1);
}

/*
** check if there's all data needed without repeats
*/
void	check_all_data(t_cub *cub)
{
	if (cub->p.res_l == 0 || cub->p.res_w == 0
	|| ft_strlen(cub->p.nor_tex) == 0
	|| ft_strlen(cub->p.sou_tex) == 0 || ft_strlen(cub->p.wes_tex) == 0
	|| ft_strlen(cub->p.eas_tex) == 0 || ft_strlen(cub->p.spr_tex) == 0
	|| cub->p.floore_flag != 1 || cub->p.ceilling_flag != 1)
	{
		ft_putstr_fd("Error\nWas set not all edificatory or ", 1);
		error("are there repetitions", cub);
	}
}

/*
** check for spaces in colors
*/
void	check_tab_in_r_f(char *line, t_cub *cub)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			error("Error\nA space was found in color", cub);
		++i;
	}
}

/*
** check ceilling
*/
void	check_c(t_cub *cub)
{
	if ((cub->p.ceilling_r > 255 || cub->p.ceilling_r < 0) ||
	(cub->p.ceilling_g > 255 || cub->p.ceilling_g < 0) ||
	(cub->p.ceilling_b > 255 || cub->p.ceilling_b < 0))
		error("Error\nNot a valid ceilling color", cub);
	cub->p.ceilling_flag = 1;
}

/*
** check floore
*/
void	check_f(t_cub *cub)
{
	if ((cub->p.floore_r > 255 || cub->p.floore_r < 0) ||
	(cub->p.floore_g > 255 || cub->p.floore_g < 0) ||
	(cub->p.floore_b > 255 || cub->p.floore_b < 0))
		error("Error\nNot a valid floor color", cub);
	cub->p.floore_flag = 1;
}

/*
** check resolution , if - return error, if bigger set to max
*/
void	check_r(t_cub *cub)
{
	int width;
	int height;

	mlx_get_screen_size(&cub->mlx, &width, &height);
	if (cub->p.res_w < 0 || cub->p.res_l < 0)
		error("Error\nNot a valid resolution", cub);
	if (cub->p.res_w > width || cub->p.res_l > height)
	{
		cub->p.res_w = width;
		cub->p.res_l = height;
	}
}

/*
** check argv '--save'
*/
int			check_av_save(char *av)
{
	if (av[0] == '-' && av[1] == '-' && av[2] == 's' &&
	av[3] == 'a' && av[4] == 'v' && av[5] == 'e')
		return (0);
	else
		return (1);
}

/*
** check argv '.cub'
*/
int			check_av_map(char *av)
{
	if (av[ft_strlen(av) - 1] == 'b' && av[ft_strlen(av) - 2] == 'u'
	&& av[ft_strlen(av) - 3] == 'c' && av[ft_strlen(av) - 4] == '.')
		return (0);
	else
		return (1);
}