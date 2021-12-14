/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:09:06 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:22:22 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__sort_3_b__(t_stack **stack, t_program_data *data)
{
	if (!((((*stack)->nbr < (*stack)->next->nbr
					&& (*stack)->next->nbr > (*stack)->next->next->nbr
					&& (*stack)->nbr < (*stack)->next->next->nbr))
			|| (((*stack)->nbr > (*stack)->next->nbr
					&& (*stack)->next->nbr < (*stack)->next->next->nbr
					&& (*stack)->nbr < (*stack)->next->next->nbr))))
		ft_swap_b(stack, data);
	if ((*stack)->nbr < (*stack)->next->nbr
		&& (*stack)->next->nbr > (*stack)->next->next->nbr
		&& (*stack)->nbr < (*stack)->next->next->nbr)
		ft_rotate_b(stack, data);
	if ((*stack)->nbr > (*stack)->next->nbr
		&& (*stack)->next->nbr < (*stack)->next->next->nbr
		&& (*stack)->nbr < (*stack)->next->next->nbr)
		ft_reverse_rotate_b(stack, data);
}

void	__sort_first_3_b__(t_stack **stack, t_program_data *data)
{
	if ((*stack)->nbr < (*stack)->next->nbr)
		ft_swap_b(stack, data);
	if ((*stack)->next->nbr < (*stack)->next->next->nbr)
	{
		ft_rotate_b(stack, data);
		ft_swap_b(stack, data);
		ft_reverse_rotate_b(stack, data);
	}
	if ((*stack)->nbr < (*stack)->next->nbr)
		ft_swap_b(stack, data);
}

int	ft_sort_three_b(t_stack **stack, t_program_data *data, int length)
{
	int	stack_len;

	stack_len = __ft_stack_len__(stack);
	if (stack_len <= 1 || length <= 1)
		return (1);
	else if (stack_len == 2 || length == 2)
	{
		if ((*stack)->nbr < (*stack)->next->nbr)
			ft_swap_b(stack, data);
		else
			return (1);
	}
	else if (stack_len == 3 && length == 3)
		__sort_3_b__(stack, data);
	else
		__sort_first_3_b__(stack, data);
	return (__SUCCESS);
}
