/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:09:34 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:39:18 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_add_back(t_stack **stack, int nbr)
{
	t_stack	*tmp;

	if (!(*stack))
		*stack = __create_elem__(nbr);
	else
	{
		tmp = (*stack);
		while (tmp)
		{
			if (tmp->next == NULL)
			{
				tmp->next = __create_elem__(nbr);
				return ;
			}
			tmp = tmp->next;
		}
		tmp = (*stack);
	}
}

void	ft_stack_add_front(t_stack **stack, int nbr)
{
	t_stack	*new;

	if (!(*stack))
		*stack = __create_elem__(nbr);
	else
	{
		new = __create_elem__(nbr);
		new->next = *stack;
		*stack = new;
	}
}

int	__is_empty__(char *str)
{
	while (*str)
	{
		if ((*str >= 9 && *str <= 13) || *str == '\0' || *str == ' ')
			str++;
		else
			return (__FAILURE);
	}
	return (__SUCCESS);
}
