/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_twin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:10:04 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:10:05 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a_b(t_stack **a, t_stack **b, t_program_data *data)
{
	if (__ft_stack_len__(a) < 2 || __ft_stack_len__(b) < 2)
		return ;
	ft_swap_a(a, data);
	ft_swap_b(b, data);
	data->nbr_ope++;
}

void	ft_rotate_a_b(t_stack **a, t_stack **b, t_program_data *data)
{
	if (!(*a) || !(*b))
		return ;
	ft_rotate_a(a, data);
	ft_rotate_b(b, data);
}

void	ft_reverse_rotate_a_b(t_stack **a, t_stack **b, t_program_data *data)
{
	if (__ft_stack_len__(a) < 2 || __ft_stack_len__(b) < 2)
		return ;
	ft_reverse_rotate_a(a, data);
	ft_reverse_rotate_b(b, data);
	data->nbr_ope++;
}
