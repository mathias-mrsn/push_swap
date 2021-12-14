/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:09:39 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/09 14:17:35 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	__is_too_long__(char *str, int j)
{
	long	nbr;

	nbr = __atol(str);
	if (j > _UINT_SIZEMAX_ || (nbr >= INT_MAX || nbr <= INT_MIN))
		return (__FAILURE);
	return (__SUCCESS);
}

static int	__string_check__(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (__FAILURE);
	while (str[index])
	{
		while (str[index] == ' ')
			index++;
		if (str[index] == '-')
			index++;
		while (str[index] && __isdigit(str[index]))
			index++;
		if (str[index] != ' ' && str[index] != '\0')
			return (__FAILURE);
	}
	index = -1;
	while (str[++index])
	{
		while (str[index] == ' ')
			index++;
		if (__is_too_long__(&str[index], 0))
			return (__FAILURE);
	}
	return (__SUCCESS);
}

int	ft_check_values(int argc, char **argv, t_program_data *data)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = __strdup("");
	if (argc < 2)
		return (__FAILURE);
	if (argc > 1)
	{
		while (++i < argc)
		{
			res = __strjoin(res, " ");
			res = __strjoin(res, argv[i]);
		}
	}
	if (__FAILURE == __is_empty__(res) && __SUCCESS == __string_check__(res))
	{
		data->string = res;
		return (__SUCCESS);
	}
	return (__putstr("Error\n", 2), __ERROR);
}

static int	__check_duplicate__(t_stack **stack, t_program_data *data)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		i;

	tmp1 = *stack;
	i = 0;
	while (tmp1)
	{
		data->nbr_elem_a++;
		i++;
		if (!tmp1->next)
			return (__SUCCESS);
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->nbr == tmp2->nbr)
				return (__FAILURE);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (__SUCCESS);
}

int	ft_edit_stack(t_stack **a, t_program_data *data)
{
	int		i;
	char	*res;

	res = data->string;
	i = 0;
	while (res[i])
	{
		while (res[i] == ' ')
			i++;
		if (!res[i])
			break ;
		ft_stack_add_back(a, (int)__atol(&res[i]));
		while (__isdigit(res[i]) || res[i] == '-')
			i++;
	}	
	if (__check_duplicate__(a, data))
		return (__clean(), __FAILURE);
	return (__SUCCESS);
}
