/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 23:48:03 by letumany          #+#    #+#             */
/*   Updated: 2021/01/24 23:51:10 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *start;

	start = (const char *)s;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
		++s;
	while (s >= start)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s--;
	}
	return (NULL);
}
