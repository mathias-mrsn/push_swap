/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:10:08 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/14 18:04:11 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_convert_in_op(t_program_data *data, t_stack **a, t_stack **b, char *str)
{
	if (!ft_strcmp(str, "sa\n") || !ft_strcmp(str, "sa\0"))
		ft_swap_a(a, data);
	else if (!ft_strcmp(str, "sb\n") || !ft_strcmp(str, "sb\0"))
		ft_swap_b(b, data);
	else if (!ft_strcmp(str, "ss\n") || !ft_strcmp(str, "ss\0"))
		ft_swap_a_b(a, b, data);
	else if (!ft_strcmp(str, "pa\n") || !ft_strcmp(str, "pa\0"))
		ft_push_a(a, b, data);
	else if (!ft_strcmp(str, "pb\n") || !ft_strcmp(str, "pb\0"))
		ft_push_b(a, b, data);
	else if (!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "ra\0"))
		ft_rotate_a(a, data);
	else if (!ft_strcmp(str, "rb\n") || !ft_strcmp(str, "rb\0"))
		ft_rotate_b(b, data);
	else if (!ft_strcmp(str, "rr\n") || !ft_strcmp(str, "rr\0"))
		ft_rotate_a_b(a, b, data);
	else if (!ft_strcmp(str, "rra\n") || !ft_strcmp(str, "rra\0"))
		ft_reverse_rotate_a(a, data);
	else if (!ft_strcmp(str, "rrb\n") || !ft_strcmp(str, "rrb\0"))
		ft_reverse_rotate_b(b, data);
	else if (!ft_strcmp(str, "rrr\n") || !ft_strcmp(str, "rrr\0"))
		ft_reverse_rotate_a_b(a, b, data);
	else
		return (__FAILURE);
	return (__SUCCESS);
}

int	ft_edit_ope(t_program_data *data, t_stack **a, t_stack **b)
{
	char	*str;

	str = __gnl(0);
	while (str)
	{
		if (ft_convert_in_op(data, a, b, str))
			return (__gnl(-1), free(str), __FAILURE);
		free(str);
		str = __gnl(0);
	}
	return (__SUCCESS);
}

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
	if (__FAILURE == ft_edit_ope(data, &a, &b))
		__putstr("Error\n", 2);
	else if (!__ft_stack_is_sort__(&a, 0))
		__printf("OK\n");
	else
		__printf("KO\n");
	return (__clean(), __SUCCESS);
}
