/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:09:56 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:18:10 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	__find_min__(t_stack **a, int min, int length)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = (*a);
	while (tmp && i++ < length)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}

static int	__find_next_min__(t_stack **a, int last_min, int length)
{
	t_stack	*tmp;
	int		min;
	int		i;

	i = 0;
	min = INT_MAX;
	tmp = (*a);
	while (tmp && i++ < length)
	{
		if (tmp->nbr > last_min && tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}

int	__find_median__(t_stack **a, int length)
{
	int	i;
	int	min;

	min = __find_min__(a, INT_MAX, length);
	i = 0;
	while (i++ < length / 2)
		min = __find_next_min__(a, min, length);
	return (min);
}
