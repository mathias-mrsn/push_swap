/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:10:02 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:35:45 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_b(t_stack **b, t_program_data *data)
{
	t_stack	*tmp;

	if (__ft_stack_len__(b) < 2)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = (*b);
	(*b) = tmp;
	data->nbr_ope++;
	ft_stack_add_back(&data->head, 2);
}

void	ft_push_b(t_stack **a, t_stack **b, t_program_data *data)
{
	if (!(*a))
		return ;
	ft_stack_add_front(b, (*a)->nbr);
	data->nbr_elem_b++;
	data->nbr_elem_a--;
	__delete_first__(a);
	ft_stack_add_back(&data->head, 5);
	data->nbr_ope++;
}

void	ft_rotate_b(t_stack **b, t_program_data *data)
{
	if (!(*b))
		return ;
	ft_stack_add_back(b, (*b)->nbr);
	__delete_first__(b);
	ft_stack_add_back(&data->head, 7);
	data->nbr_ope++;
}

void	ft_reverse_rotate_b(t_stack **b, t_program_data *data)
{
	t_stack	*tmp;

	tmp = (*b);
	if (__ft_stack_len__(b) < 2)
		return ;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			ft_stack_add_front(b, tmp->nbr);
			__delete_last__(b);
			break ;
		}
		tmp = tmp->next;
	}
	ft_stack_add_back(&data->head, 10);
	data->nbr_ope++;
}
