/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:09:12 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:09:12 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_must_delete(int a, int b)
{
	if (a == b && (a == 1 || a == 2 || a == 3))
		return (__SUCCESS);
	if ((a == 4 && b == 5) || (a == 5 && b == 4))
		return (__SUCCESS);
	if ((a == 6 && b == 9) || (a == 9 && b == 6))
		return (__SUCCESS);
	if ((a == 7 && b == 10) || (a == 10 && b == 7))
		return (__SUCCESS);
	if ((a == 8 && b == 11) || (a == 11 && b == 8))
		return (__SUCCESS);
	return (__FAILURE);
}

int	__change__(int a, int b)
{
	if ((a == 1 && b == 2) || (a == 2 && b == 1))
		return (3);
	if ((a == 7 && b == 6) || (a == 6 && b == 7))
		return (8);
	if ((a == 9 && b == 10) || (a == 10 && b == 9))
		return (11);
	return (__FAILURE);
}

void	__delete_elem__(t_stack **head, t_stack *prev, t_stack *next)
{
	t_stack	*del;
	t_stack	*del2;

	del2 = next;
	del = NULL;
	if (prev)
		del = prev->next;
	if (!prev)
		(*head) = next->next;
	else if (!next->next)
		prev->next = NULL;
	else
		prev->next = next->next;
	next = next->next;
}

void	__change_op__(t_stack **head, t_stack *prev, t_stack *next, int op)
{
	t_stack	*del;

	del = NULL;
	next->nbr = op;
	if (prev)
		del = prev->next;
	if (!prev)
		(*head) = next;
	else
		prev->next = next;
}
