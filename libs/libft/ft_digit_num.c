/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <letumany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 22:57:16 by letumany          #+#    #+#             */
/*   Updated: 2021/07/30 20:52:03 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digit_num(long int n)
{
	int tmp;
	int tmp2;

	tmp2 = (int)n;
	tmp = 1;
	if (n < 0)
		++tmp;
	while ((tmp2 = tmp2 / 10))
		++tmp;
	return (tmp);
}