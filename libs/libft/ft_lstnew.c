/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:48:23 by letumany          #+#    #+#             */
/*   Updated: 2021/02/06 21:48:14 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *obj;

	if (!(obj = malloc(sizeof(t_list))))
		return (NULL);
	obj->content = content;
	obj->next = NULL;
	return (obj);
}
