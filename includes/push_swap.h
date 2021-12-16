/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:10:38 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/16 09:40:00 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define _UINT_SIZEMAX_ 12

# include "libft.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}				t_stack;

typedef struct s_program_data
{
	int				data_type;
	int				nbr_elem_a;
	int				nbr_elem_b;
	int				nbr_ope;
	char			*string;
	struct s_stack	*head;

}				t_program_data;

//		 INITIALISATION

int			ft_edit_stack(t_stack **a, t_program_data *data);
int			ft_check_values(int argc, char **argv, t_program_data *data);

//		 TOOLS

int			__is_empty__(char *str);
t_stack		*__create_elem__(int nbr);
int			__ft_stack_len__(t_stack **stack);
void		__delete_last__(t_stack **stack);
void		__delete_first__(t_stack **stack);
void		ft_stack_add_back(t_stack **stack, int nbr);
void		ft_stack_add_front(t_stack **stack, int nbr);
int			__ft_stack_is_sort__(t_stack **stack, int direction);
int			__is_empty__(char *str);

//		 OPERATIONS

void		ft_swap_a(t_stack **a, t_program_data *data);
void		ft_swap_b(t_stack **b, t_program_data *data);
void		ft_rotate_a(t_stack **a, t_program_data *data);
void		ft_rotate_b(t_stack **b, t_program_data *data);
void		ft_reverse_rotate_a(t_stack **a, t_program_data *data);
void		ft_reverse_rotate_b(t_stack **b, t_program_data *data);
void		ft_swap_first_last_a(t_stack **a, t_program_data *data);
void		ft_swap_first_last_b(t_stack **b, t_program_data *data);
void		ft_push_b(t_stack **a, t_stack **b, t_program_data *data);
void		ft_push_a(t_stack **a, t_stack **b, t_program_data *data);
void		ft_swap_a_b(t_stack **a, t_stack **b, t_program_data *data);
void		ft_rotate_a_b(t_stack **a, t_stack **b, t_program_data *data);
void		ft_reverse_rotate_a_b(t_stack **a,
				t_stack **b, t_program_data *data);

//		 SORT THREE

int			ft_sort_three_a(t_stack **stack, t_program_data *data, int length);
int			ft_sort_three_b(t_stack **stack, t_program_data *data, int length);

//		REDUCE OPERATIONS NUMBER

void		ft_least_ope_starter(t_stack **stack, t_program_data *data);
int			ft_must_delete(int a, int b);
int			__change__(int a, int b);
void		__delete_elem__(t_stack **head, t_stack *prev, t_stack *next);
void		__change_op__(t_stack **head, t_stack *prev, t_stack *next, int op);

//		PRINT OPERATIONS

void		ft_print_ope(t_stack **stack);

//		ALGORITH

int			__find_median__(t_stack **a, int length);
int			ft_sort_a(t_stack **a, t_stack **b,
				t_program_data *data, int length);
int			ft_sort_b(t_stack **a, t_stack **b,
				t_program_data *data, int length);

#endif
