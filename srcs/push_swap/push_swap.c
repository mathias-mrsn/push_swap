/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:09:29 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:09:30 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	t_program_data	*data;

	a = NULL;
	b = NULL;
	data = __malloc(sizeof(t_program_data));
	if (!data)
		return (__clean(), __putstr("Error\n", 2), __FAILURE);
	if (ft_check_values(argc, argv, data))
		return (__clean(), __FAILURE);
	if (ft_edit_stack(&a, data))
		return (__clean(), __putstr("Error\n", 2), __FAILURE);
	if (__ft_stack_is_sort__(&a, 0))
		ft_sort_a(&a, &b, data, __ft_stack_len__(&a));
	if (data->head)
		ft_least_ope_starter(&data->head, data);
	ft_print_ope(&data->head);
	return (__clean(), __SUCCESS);
}
