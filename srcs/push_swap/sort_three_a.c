/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:09:09 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:36:36 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	__sort_3_a__(t_stack **stack, t_program_data *data)
{
	if (!((((*stack)->nbr > (*stack)->next->nbr
					&& (*stack)->next->nbr < (*stack)->next->next->nbr
					&& (*stack)->nbr > (*stack)->next->next->nbr))
			|| (((*stack)->nbr < (*stack)->next->nbr
					&& (*stack)->next->nbr > (*stack)->next->next->nbr
					&& (*stack)->nbr > (*stack)->next->next->nbr))))
		ft_swap_a(stack, data);
	if ((*stack)->nbr > (*stack)->next->nbr
		&& (*stack)->next->nbr < (*stack)->next->next->nbr
		&& (*stack)->nbr > (*stack)->next->next->nbr)
		ft_rotate_a(stack, data);
	if ((*stack)->nbr < (*stack)->next->nbr
		&& (*stack)->next->nbr > (*stack)->next->next->nbr
		&& (*stack)->nbr > (*stack)->next->next->nbr)
		ft_reverse_rotate_a(stack, data);
}

static void	__sort_first_3_a__(t_stack **stack, t_program_data *data)
{
	if ((*stack)->nbr > (*stack)->next->nbr)
		ft_swap_a(stack, data);
	if ((*stack)->next->nbr > (*stack)->next->next->nbr)
	{
		ft_rotate_a(stack, data);
		ft_swap_a(stack, data);
		ft_reverse_rotate_a(stack, data);
	}
	if ((*stack)->nbr > (*stack)->next->nbr)
		ft_swap_a(stack, data);
}

int	ft_sort_three_a(t_stack **stack, t_program_data *data, int length)
{
	int	stack_len;

	stack_len = __ft_stack_len__(stack);
	if (stack_len <= 1 || length <= 1)
		return (1);
	else if (stack_len == 2 || length == 2)
	{
		if ((*stack)->nbr > (*stack)->next->nbr)
			ft_swap_a(stack, data);
		else
			return (1);
	}
	else if (stack_len == 3 && length == 3)
		__sort_3_a__(stack, data);
	else
		__sort_first_3_a__(stack, data);
	return (__SUCCESS);
}
