/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:09:37 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:35:45 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*__create_elem__(int nbr)
{
	t_stack	*new;

	new = __malloc(sizeof(t_stack) * 1);
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

void	__delete_first__(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if ((*stack)->next)
		*stack = (*stack)->next;
	else
	{
		*stack = NULL;
		return ;
	}
}

void	__delete_last__(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*del;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	del = tmp->next;
	tmp->next = NULL;
}

int	__ft_stack_is_sort__(t_stack **stack, int direction)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*stack))
		return (0);
	tmp = *stack;
	tmp2 = tmp->next;
	while (tmp && tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (direction == 0 && tmp->nbr > tmp2->nbr)
				return (__FAILURE);
			if (direction == 1 && tmp->nbr < tmp2->nbr)
				return (__FAILURE);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (__SUCCESS);
}

int	__ft_stack_len__(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
