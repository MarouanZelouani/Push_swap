/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:57:31 by mzelouan          #+#    #+#             */
/*   Updated: 2024/03/05 03:45:29 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack
{
	int				data;
	int				index;
	int				to_push;
	int				target;
	struct stack	*next;
}					t_stack;

typedef struct s_sort_param
{
	int				*array;
	int				mid;
	int				offset;
	int				start;
	int				end;
	int				size;
}					t_param;

void				init_stack(t_stack **stack_a, char **av);
int					is_all_digits(char **av);
int					exist_duplicates(char **av);
int					is_sorted(t_stack *s);
int					ft_stack_size(t_stack *s);
t_stack				*get_min_in_stack(t_stack *s);
t_stack				*get_max_in_stack(t_stack *s);
void				set_index_to_node(t_stack *s);
t_stack				*get_node(t_stack *s, int data);
void				sort_three(t_stack **a);
void				sort_stack(t_stack **a, t_stack **b);
void				swap(t_stack **s);
void				swap_a(t_stack **a, int true);
void				swap_b(t_stack **b, int true);
void				swap_ab(t_stack **a, t_stack **b, int true);
void				push(t_stack **s, t_stack *top);
t_stack				*pop(t_stack **s);
void				push_a(t_stack **a, t_stack **b, int true);
void				push_b(t_stack **a, t_stack **b, int true);
void				rotate(t_stack **s);
void				rotate_a(t_stack **a, int true);
void				rotate_b(t_stack **b, int true);
void				rotate_ab(t_stack **a, t_stack **b, int true);
void				reverse_rotate(t_stack **s);
void				reverse_rotate_a(t_stack **a, int true);
void				reverse_rotate_b(t_stack **b, int true);
void				reverse_rotate_ab(t_stack **a, t_stack **b, int true);
void				execute_instructions(t_stack **a, t_stack **b);
void				free_vector(char **av);
void				free_stack(t_stack *head);
int					dup_checker(t_stack *s);

// ALGO
void				sort(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				insertion_sort(int *arr, int n);
int					exist_in_a(t_stack *a, int value);
int					divider(t_stack *a);
t_stack				*get_last_node(t_stack *a);
void				fix_stack_b(t_stack **b, t_param param);
int					*dup_array(t_stack *a);
int					belong_to_the_range(int value, t_param param);
int					return_first_match(t_stack *a, t_param param);

#endif
