/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 11:48:41 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 11:52:25 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*__malloc(size_t size)
{
	static t_list	*lst = NULL;
	void			*ret;

	ret = NULL;
	if (size)
	{
		ret = __calloc(1, size);
		__lstadd_front(&lst, __lstnew(ret));
	}
	if (0 == size)
		return (&lst);
	return (ret);
}
