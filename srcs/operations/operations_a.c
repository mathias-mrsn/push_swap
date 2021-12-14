/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:10:00 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:35:45 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack **a, t_program_data *data)
{
	t_stack	*tmp;

	if (__ft_stack_len__(a) < 2)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = (*a);
	(*a) = tmp;
	data->nbr_ope++;
	ft_stack_add_back(&data->head, 1);
}

void	ft_push_a(t_stack **a, t_stack **b, t_program_data *data)
{
	if (!(*b))
		return ;
	ft_stack_add_front(a, (*b)->nbr);
	data->nbr_elem_a++;
	data->nbr_elem_b--;
	__delete_first__(b);
	ft_stack_add_back(&data->head, 4);
	data->nbr_ope++;
}

void	ft_rotate_a(t_stack **a, t_program_data *data)
{
	if (!(*a))
		return ;
	ft_stack_add_back(a, (*a)->nbr);
	__delete_first__(a);
	ft_stack_add_back(&data->head, 6);
	data->nbr_ope++;
}

void	ft_reverse_rotate_a(t_stack **a, t_program_data *data)
{
	t_stack	*tmp;

	tmp = (*a);
	if (__ft_stack_len__(a) < 2)
		return ;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			ft_stack_add_front(a, tmp->nbr);
			__delete_last__(a);
			break ;
		}
		tmp = tmp->next;
	}
	ft_stack_add_back(&data->head, 9);
	data->nbr_ope++;
}
