/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_ope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:09:14 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:09:26 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	__reset__(t_stack **stack, t_stack **prev,
	t_stack **curr, t_stack **next)
{
	(*prev) = NULL;
	(*curr) = (*stack);
	(*next) = (*curr)->next;
}

void	ft_least_ope_starter(t_stack **stack, t_program_data *data)
{
	t_stack	*prev;
	t_stack	*curr;
	t_stack	*next;
	int		switch_op;

	prev = NULL;
	curr = (*stack);
	next = curr->next;
	while (curr && next)
	{
		switch_op = __change__(curr->nbr, next->nbr);
		if ((__SUCCESS == ft_must_delete(curr->nbr, next->nbr)))
		{
			switch_op = -1;
			data->nbr_ope -= 2;
			__delete_elem__(stack, prev, next);
		}
		else if (1 != __change__(curr->nbr, next->nbr) && data->nbr_ope--)
			__change_op__(stack, prev, next, switch_op);
		prev = curr;
		curr = next;
		next = next->next;
		if (switch_op == -1)
			__reset__(stack, &prev, &curr, &next);
	}
}
