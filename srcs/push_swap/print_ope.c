/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:09:32 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:16:04 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	__convert_nb_to_op__(int nbr)
{
	const char	*tab[11] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};

	if (nbr < 12 && nbr > 0)
		__printf("%s\n", tab[nbr - 1]);
}

void	ft_print_ope(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		__convert_nb_to_op__(tmp->nbr);
		tmp = tmp->next;
	}
}
