/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:41:25 by mzelouan          #+#    #+#             */
/*   Updated: 2024/03/07 18:47:21 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_first_match(t_stack **a, t_stack **b, t_param param)
{
	int	first_match;

	first_match = return_first_match(*a, param);
	while ((*a)->data != first_match)
	{
		if (get_node(*a, first_match)->index <= ft_stack_size(*a) / 2)
			rotate_a(a, 1);
		else
			reverse_rotate_a(a, 1);
	}
	push_b(a, b, 1);
}

int	doooo(t_stack **b, t_stack **a, t_param param, int *i)
{
	if ((*b)->data == param.array[*i])
	{
		push_a(a, b, 1);
		(*i)--;
		return (1);
	}
	else if (exist_in_a(*a, param.array[*i]))
	{
		while ((*a)->data != param.array[*i])
			reverse_rotate_a(a, 1);
		(*i)--;
		return (1);
	}
	return (0);
}

void	fix(t_stack **a, int min)
{
	while ((*a)->data > min)
		reverse_rotate_a(a, 1);
}

void	push_to_b(t_stack **a, t_stack **b, t_param p)
{
	int	i;

	i = p.size - 1;
	while (ft_stack_size(*b))
	{
		if (!doooo(b, a, p, &i))
		{
			set_index_to_node(*b);
			if (ft_stack_size(*a) >= 1
				&& (get_last_node(*a)->data == p.array[p.size - 1]
					|| (*b)->data > get_last_node(*a)->data))
			{
				push_a(a, b, 1);
				rotate_a(a, 1);
			}
			else
			{
				if (get_node(*b, p.array[i])->index <= ft_stack_size(*b) / 2)
					rotate_b(b, 1);
				else
					reverse_rotate_b(b, 1);
			}
		}
	}
	fix(a, p.array[0]);
}

void	sort(t_stack **a, t_stack **b)
{
	t_param	param;
	int		block_size;

	param.array = dup_array(*a);
	insertion_sort(param.array, ft_stack_size(*a));
	param.size = ft_stack_size(*a);
	param.mid = ft_stack_size(*a) / 2 - 1;
	param.offset = ft_stack_size(*a) / divider(*a);
	param.start = param.mid - param.offset;
	param.end = param.mid + param.offset;
	block_size = param.end - param.start + 1;
	while (ft_stack_size(*a))
	{
		if (ft_stack_size(*b) == block_size)
		{
			param.start -= param.offset;
			param.end += param.offset;
			block_size = param.end - param.start + 1;
		}
		push_first_match(a, b, param);
		fix_stack_b(b, param);
		set_index_to_node(*a);
	}
	push_to_b(a, b, param);
	free(param.array);
}
