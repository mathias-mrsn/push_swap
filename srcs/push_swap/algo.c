/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:09:43 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:19:07 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	__replace_a__(t_stack **a,
	t_program_data *data, int nbr_rotate, int elem_pushed)
{
	if (__ft_stack_len__(a) - elem_pushed > 3)
	{
		if (nbr_rotate <= __ft_stack_len__(a) / 2)
			while (nbr_rotate--)
				ft_reverse_rotate_a(a, data);
		else
			while (nbr_rotate++ < __ft_stack_len__(a))
				ft_rotate_a(a, data);
	}
}

static void	__replace_b__(t_stack **b,
	t_program_data *data, int nbr_rotate, int elem_pushed)
{
	if (__ft_stack_len__(b) - elem_pushed > 3)
	{
		if (nbr_rotate <= __ft_stack_len__(b) / 2)
			while (nbr_rotate--)
				ft_reverse_rotate_b(b, data);
		else
			while (nbr_rotate++ < __ft_stack_len__(b))
				ft_rotate_b(b, data);
	}
}

static int	__something_to_push__(t_stack **stack,
	int pivot, int length, char type)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp && i++ < length)
	{
		if (type == 'a' && tmp->nbr < pivot)
			return (__SUCCESS);
		if (type == 'b' && tmp->nbr > pivot)
			return (__SUCCESS);
		tmp = tmp->next;
	}
	return (__FAILURE);
}

int	ft_sort_b(t_stack **a, t_stack **b, t_program_data *data, int length)
{
	const int	pivot = __find_median__(b, length);
	int			elem_pushed;
	int			nbr_rotate;
	int			i;

	if (length <= 3)
		return (ft_sort_three_b(b, data, length));
	elem_pushed = 0;
	nbr_rotate = 0;
	i = 0;
	while (i++ < length && !__something_to_push__(b, pivot, length, 'b'))
	{
		if ((*b)->nbr > pivot && ++elem_pushed)
			ft_push_a(a, b, data);
		else if (++nbr_rotate)
			ft_rotate_b(b, data);
	}
	__replace_b__(b, data, nbr_rotate, elem_pushed);
	if (__ft_stack_is_sort__(a, 0))
		ft_sort_a(a, b, data, elem_pushed);
	if (__ft_stack_is_sort__(b, 1))
		ft_sort_b(a, b, data, length - elem_pushed);
	while (elem_pushed--)
		ft_push_b(a, b, data);
	return (0);
}

int	ft_sort_a(t_stack **a, t_stack **b, t_program_data *data, int length)
{
	const int	pivot = __find_median__(a, length);
	int			elem_pushed;
	int			nbr_rotate;
	int			i;

	if (length <= 3)
		return (ft_sort_three_a(a, data, length));
	elem_pushed = 0;
	nbr_rotate = 0;
	i = 0;
	while (i++ < length && !__something_to_push__(a, pivot, length, 'a'))
	{
		if ((*a)->nbr < pivot && ++elem_pushed)
			ft_push_b(a, b, data);
		else if (++nbr_rotate)
			ft_rotate_a(a, data);
	}
	__replace_a__(a, data, nbr_rotate, elem_pushed);
	if (__ft_stack_is_sort__(a, 0))
		ft_sort_a(a, b, data, length - elem_pushed);
	if (__ft_stack_is_sort__(b, 1))
		ft_sort_b(a, b, data, elem_pushed);
	while (elem_pushed--)
		ft_push_a(a, b, data);
	return (0);
}
