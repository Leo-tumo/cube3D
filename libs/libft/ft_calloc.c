/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:10:09 by letumany          #+#    #+#             */
/*   Updated: 2021/01/30 18:58:53 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *allocated;

	if (!(allocated = malloc(count * size)))
		return (NULL);
	ft_memset(allocated, '\0', (count * size));
	return (allocated);
}
